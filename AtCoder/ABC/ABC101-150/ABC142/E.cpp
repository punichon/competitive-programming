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
#include<bitset>

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
typedef tuple<ll, ll, ll, ll> lltpl;



/******************************************************************************************/


const int IINF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const ll MOD = 1e9 + 7;



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


ll dp[1 << 14];

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	vector<int> a(M), b(M), c(M, 0);


	for (int i = 0; i < M; i++)
	{
		cin >> a[i] >> b[i];

		int cnt = 0;
		for (int j = 0; j < b[i]; j++)
		{
			int t;
			cin >> t;
			cnt += (1 << (t - 1));
		}
		c[i] = cnt;
	}
	for (int i = 0; i < 1 << 14 - 1; i++)
	{
		dp[i] = LINF;
	}

	dp[0] = 0;

	for (int i = 0; i < (1 << N); i++)
	{
		for (int j = 0; j < M; j++)
		{
			bool can_use = false;

			for (int mask = 13; mask >= 0; mask--) {

				if (!((i >> mask) & 1)) {
					//bitが立っていない（まだ使っていない）
					can_use = true;
					break;
				}
			}

			if (can_use) {
				//j番目を使う
				
				dp[(i | c[j])] = min(dp[(i | c[j])], dp[i] + a[j]);
			}
		}
	}

	if (dp[(1 << N) - 1] == LINF) {
		cout << "-1" << endl;
	}
	else
	{
		cout << dp[(1 << N) - 1] << endl;
	}

}

