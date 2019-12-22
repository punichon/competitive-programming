#include<algorithm>
#include<bitset>
#include<cassert>
#include<cfloat>
#include<climits>
#include<cmath>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>
#include<complex>

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

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };


/******************************************************************************************/


vector<int> g[100005];
bool check[100005];
bool check2[100005];

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);


	int n, u, v;
	cin >> n >> u >> v;
	u--;
	v--;
	
	
	for (int i = 0; i < n - 1; i++) {
		//cout << "i= " << i << endl;
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x].emplace_back(y);
		g[y].emplace_back(x);
	}
	//cout << "a" << endl;

	queue<int> que;
	que.push(u);

	vector<int> dist(100005, INF);
	dist[u] = 0;


	while (!que.empty()) {

		int now = que.front();
		que.pop();
		if (check[now] == 1)continue;
		check[now] = 1;

		for (int nxt : g[now]) {

			if (check[nxt] == 0) {

				if (dist[nxt] > dist[now] + 1) {
					dist[nxt] = dist[now] + 1;
					que.push(nxt);
				}
			}
		}
	}


	vector<int> dist2(100005, INF);
	dist2[v] = 0;
	que.push(v);

	while (!que.empty()) {

		int now = que.front();
		que.pop();
		if (check2[now] == 1)continue;
		check2[now] = 1;

		for (int nxt : g[now]) {

			if (check2[nxt] == 0) {

				if (dist2[nxt] > dist2[now] + 1) {
					dist2[nxt] = dist2[now] + 1;
					que.push(nxt);
				}
			}
		}
	}

	
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (dist[i] < dist2[i]) {

			//高橋君からの方が近い
			ans = max(ans, dist2[i] - 1);
		}

	}
	cout << ans << endl;


	return 0;
}
