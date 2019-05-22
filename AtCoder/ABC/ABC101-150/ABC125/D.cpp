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

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)

using namespace std;
typedef pair<int, int> pii;

typedef long long int ll;



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
const ll INF = 1e14 + 7;



//ユークリッド互除法
template<typename T>
T gcd(T x, T y) {

	if (y == 0) {
		return x;
	}
	else {
		return gcd(y, x % y);
	}
}

ll dp[ARRAY_MAX][2];

int main() {

	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}


	for (int i = 0; i < ARRAY_MAX; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			dp[i][j] = -INF;
		}
	}

	dp[0][0] = 0;
	for (ll i = 0; i < n - 1; i++)
	{
		if (i == 0)
		{
			dp[i + 1][0] = max(dp[i + 1][0], dp[0][0] + a[i]);
			dp[i + 1][1] = max(dp[i + 1][1], dp[0][0] - a[i]);
		}
		else
		{
			for (int j = 0; j < 2; j++)
			{
				if (j == 0)
				{
					//自身は変化していない時
					dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + a[i] * (-1));//変える時
					dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + a[i]);//変えない場合
				}
				else
				{
					//自信が既に変化している場合
					dp[i + 1][0] = max(dp[i + 1][0], dp[i][1] - a[i]);//変えない場合次のは変わらない
					dp[i + 1][1] = max(dp[i + 1][1], dp[i][1] + a[i]);//変える場合次のは変わる
				}
			}
		}
		
	}

	

	cout << max(dp[n-1][1] - a[n-1], dp[n-1][0] + a[n-1]) << endl;
}



