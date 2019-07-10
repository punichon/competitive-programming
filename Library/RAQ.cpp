
template<typename T>
struct SqrtDecomposition {
private:
	const int sqrtN = 1024;
	T N, K;
	vector<T> data;
	vector<T> bucketAdd;
public:
	SqrtDecomposition(T n) : N(n) {
		K = (N + sqrtN - 1) / sqrtN;
		data.assign(K * sqrtN, 0);
		bucketAdd.assign(K, 0);
	}
	void add(T s, T t, T x) {
		for (T k = 0; k < K; ++k) {
			T l = k * sqrtN, r = (k + 1) * sqrtN;
			if (r <= s || t <= l)
				continue;
			if (s <= l && r <= t) {
				bucketAdd[k] += x;
			}
			else {
				for (T i = max(s, l); i < min(t, r); ++i) {
					data[i] += x;
				}
			}
		}
	}
	// [x, y)
	T get(T s) {
		int k = s / sqrtN;
		return data[s] + bucketAdd[k];
	}
};
