
template<typename T>
T LIS(vector<T>& a) {/*長さに対する最小の最終要素*/

	T siz = a.size();
	vector<T> dp(a.size() + 10, INF);

	for (T i = 0; i < siz; i++) {
		*lower_bound(dp.begin(), dp.begin() + siz, a[i]) = a[i];
	}
	return lower_bound(dp.begin(), dp.begin() + siz, INF) - dp.begin();
}
