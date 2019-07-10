

//RMQ
//セグ木
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
		node.resize(2 * N - 1, INF);
	}

	void build(vector<T>& dat) {
		for (int i = 0; i < dat.size(); i++) {
			node[i + N - 1] = dat[i];
		}
		for (int i = N - 2; i >= 0; i--) {
			node[i] = min(node[2 * i + 1], node[2 * i + 2]);
		}
	}

	void update(T k, T x) {
		k += N - 1;
		node[k] = x;
		while (k > 0) {
			k = (k - 1) / 2;//親
			node[k] = min(node[2 * k + 1], node[2 * k + 2]);
		}
	}

	//[a,b)
	T getMin(T a, T b) {
		return getMin(a, b, 0, 0, N);
	}

	T getMin(T a, T b, T k, T l, T r) {
		if (r <= a || b <= l) {
			return INF;
		}
		if (a <= l && r <= b) {
			return node[k];
		}
		T vl = getMin(a, b, k * 2 + 1, l, (l + r) / 2);
		T vr = getMin(a, b, k * 2 + 2, (l + r) / 2, r);
		return min(vl, vr);
	}

	T find(T a, T b, T x) {
		return (find(a, b, x, 0, 0, N));
	}

	//頂点k(区間[l,r)の)の部分木について区間[a,b)内でx以下の値を持つ要素の最右位置を返す
	T find(T a, T b, T x, T k, T l, T r) {
		if (node[k] > x || r <= a || b <= l) {
			//自分の頂点がxより大きいか範囲外の場合、この区間にないため-1を返す
			return -1;
		}
		if (k >= N - 1) {
			//自分の頂点が葉なら見つかったことになるので、その位置を返す
			return (k - (N - 1));
		}
		//右の区間の部分木を見る
		T rv = find(a, b, x, 2 * k + 2, (l + r) >> 1, r);
		if (rv != -1) {
			//戻り値が-1以外なら見つかったのでその位置を返す
			return rv;
		}
		//右の部分偽になかったので左の部分木を調べる
		return (find(a, b, x, 2 * k + 1, l, (l + r) >> 1));
	}
};



//平方分割

template<typename T>
struct SqrtDecomposition {

private:
	const T INF = (1LL << 31) - 1;
	const T sqrtN = 1024;
	T N, K;
	vector<T> data;
	vector<T> bucketMin;
public:
	SqrtDecomposition(T n) : N(n) {
		K = (N + sqrtN - 1) / sqrtN;
		data.assign(K * sqrtN, INF);
		bucketMin.assign(K, INF);
	}
	void update(T x, T y) {
		T k = x / sqrtN;
		T minVal = data[x] = y;
		for (T i = k * sqrtN; i < (k + 1) * sqrtN; ++i) {
			minVal = min(minVal, data[i]);
		}
		bucketMin[k] = minVal;
	}
	// [x, y)
	T find(T x, T y) {
		int minVal = INF;
		for (T k = 0; k < K; ++k) {
			T l = k * sqrtN, r = (k + 1) * sqrtN;
			if (r <= x || y <= l)
				continue;
			if (x <= l && r <= y) {
				minVal = min(minVal, bucketMin[k]);
			}
			else {
				for (int i = max(x, l); i < min(y, r); ++i) {
					minVal = min(minVal, data[i]);
				}
			}
		}
		return minVal;
	}
};

