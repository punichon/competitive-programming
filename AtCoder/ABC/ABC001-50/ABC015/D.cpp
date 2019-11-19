#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<climits>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


template<typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }
template<typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
	return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}
template<typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T& t, const V& v) { t = v; }
template<typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T& t, const V& v) {
	for (auto& e : t) fill_v(e, v);
}


#define ARRAY_MAX 100005
const int INF = INT32_MAX / 3;
const ll MOD = 1e9 + 7;

int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };


/******************************************************************************************/


//BinaryIndexTree(siz):長さsizで初期化
//sum(k):区間[0,k]の和を求める
//add(k,x):要素kにxを加える

template<typename T>
struct BinaryIndexTree {

	int n;
	vector<T> data;

	BinaryIndexTree(int siz)
	{
		n = siz;
		//1-indexなので配列は1つ多めに用意する
		data.resize(siz + 1, 0);
	}


	T sum(int k) {

		//[0,k)までの和を計算
		T ret = 0;
		while (k > 0) {
			ret += data[k - 1];
			k -= k & -k;
		}
		return ret;
	}

	//0-index
	void add(int k, int x)
	{
		//a_kにxを加算する
		while (k <= n) {
			data[k - 1] += x;
			k += k & -k;
		}
	}


	// bitに入ってる中でx番目に小さい数を求める
	// 1番小さい数はx = 1;
	// bitに3を入れる→add(3, 1), 3を出す→add(3, -1)
	// return == nの場合x個も入っていない
	ll min_xth(int x) {
		int left = -1, right = n;
		while (left + 1 < right) {
			int mid = (left + right) / 2;
			int temp = sum(mid + 1);
			if (temp < x) {
				left = mid;
			}
			else {
				right = mid;
			}
		}
		return right;
	}


	// pを順番通りにするための交換回数
	ll bubble(vector<T> p) {
		int n = p.size();
		ll ans = 0;
		for (int j = 0; j < n; j++) {
			ans += (j - sum(p[j] + 1));
			add(p[j], 1);
		}
		return ans;
	}


};

int dp[55][10005];

int main() {


	int w, n, k;
	cin >> w >> n >> k;
	vector<pii> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
	{
		for (int k = n - 1; k >= 0; k--)
		{
			for (int j = w; j >= 0; j--) {
				if (j + v[i].first > w) {
					continue;
				}
				dp[k + 1][j + v[i].first] = max(dp[k + 1][j + v[i].first], dp[k][j] + v[i].second);
			}

		}
	}

	int ans = 0;

	for (int i = 0; i <= k; i++)
	{
		for (int j = 0; j <= w; j++)
		{
			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans << endl;



	return 0;
}
