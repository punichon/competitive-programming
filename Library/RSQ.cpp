
const int sqrtN = 1024;

template<typename T>
struct SqrtDecomposition {
	//RSQ(平方分割)
private:
	T N, K;
	vector<T> data;
	vector<T> bucketSum;
public:
	SqrtDecomposition(T n) : N(n) {
		K = (N + sqrtN - 1) / sqrtN;
		data.assign(K * sqrtN, 0);
		bucketSum.assign(K, 0);
	}
	void add(T x, T y) {
		T k = x / sqrtN;
		data[x] += y;
		T sum = 0;
		for (T i = k * sqrtN; i < (k + 1) * sqrtN; ++i) {
			sum += data[i];
		}
		bucketSum[k] = sum;
	}
	// [x, y)
	T getSum(T x, T y) {
		int sum = 0;
		for (int k = 0; k < K; ++k) {
			T l = k * sqrtN, r = (k + 1) * sqrtN;
			if (r <= x || y <= l)
				continue;
			if (x <= l && r <= y) {
				sum += bucketSum[k];
			}
			else {
				for (T i = max(x, l); i < min(y, r); ++i) {
					sum += data[i];
				}
			}
		}
		return sum;
	}
};




//RSQ(セグ木)
template<typename T>
struct SegmentTree {

private:
	T N;
	vector<T> node;//0-index

public:
	SegmentTree(T siz) {
		N = 1;
		while (N < siz) {
			N *= 2;
		}
		node.resize(2 * N - 1, 0);
	}

	void build(vector<T>& dat) {
		for (T i = 0; i < dat.size(); i++) {
			node[i + N - 1] = dat[i];
		}
		for (T i = N - 2; i >= 0; i--) {
			node[i] = node[2 * i + 1] + node[2 * i + 2];
		}
	}

	void update(T k, T x) {
		k += N - 1;
		node[k] += x;
		while (k > 0) {
			k = (k - 1) / 2;//親
			node[k] = node[2 * k + 1] + node[2 * k + 2];
		}
	}

	T getSum(T a, T b) {
		return getSum(a, b, 0, 0, N);
	}
	T getSum(T a, T b, T k, T l, T r) {
		if (r <= a || b <= l) {
			return 0;
		}
		if (a <= l && r <= b) {
			return node[k];
		}
		T vl = getSum(a, b, k * 2 + 1, l, (l + r) / 2);
		T vr = getSum(a, b, k * 2 + 2, (l + r) / 2, r);
		return vl + vr;
	}

	//頂点kの部分木についてx番目に小さい要素位置を返す
	T binary_search(T &x, T k) {//xは参照渡しで1-indexとする
		if (node[k] < x) {
			//自分の頂点がxよりも小さいならxからその頂点の値を引いてreturn -1(この区間だけだと足りない)
			x -= node[k];
			return -1;
		}
		if (k >= N - 1) {
			//自分の頂点が葉なら見つかったことになるので、その位置を返す
			return (k - (N - 1));
		}
		//右の区間の部分木を見る
		T p = binary_search(x, 2 * k + 1);
		if (p != -1) {
			//戻り値が-1以外なら見つかったのでその位置を返す
			return p;
		}
		//右の部分木になかったので左の部分木を調べる
		return (binary_search(x, 2 * k + 2));
	}
};