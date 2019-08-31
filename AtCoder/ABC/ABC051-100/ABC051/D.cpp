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
using namespace std;

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define VSORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)


typedef long long ll;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


/*************************************************************************/
//多次元配列の確保及び初期化用マクロ
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
/*************************************************************************/



const ll INF = 1e9 + 7;

#define ARRAY_MAX 100005



void warshall_floyd(int v, vector<vector<ll> >& d) {
	/*頂点の個数、コスト:d[u][v]はe=(u,v)のコスト(存在しない場合はINF,ただしd[i][j]=0とする)*/

	for (int k = 0; k < v; k++) {
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++) {
				if (d[i][k] == INF || d[k][j] == INF)
				{
					continue;
				}
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				//kを通る経路と通らない経路の最小値をとる
			}
		}
	}
}




int main() {

	ll n, m;
	cin >> n >> m;

	auto mp = make_v<ll>(n + 10, n + 10);
	auto dp = make_v<ll>(n + 10, n + 10);
	fill_v(mp, INF);
	fill_v(dp, INF);

	for (int i = 0; i < n; i++)
	{
		mp[i][i] = dp[i][i] = 0;
	}
	   
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		mp[a][b] = mp[b][a] = c;
		dp[a][b] = dp[b][a] = c;
	}

	int pass_siz = 0;

	warshall_floyd(n, dp);

	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (mp[i][j] == INF)
			{
				continue;
			}
			if (dp[i][j] != mp[i][j])
			{
				pass_siz++;
			}
		}
	}

	cout << pass_siz << endl;
	return 0;
}
