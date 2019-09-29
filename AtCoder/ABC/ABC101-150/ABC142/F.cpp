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
#include<stack>

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

//グラフの隣接リスト
vector<int> g[1010];
int n, m;

vector<int> bfs(int now) {

	vector<int> dist(n, IINF), prev(n, -1);
	queue<int> que;
	dist[now] = 0;

	que.push(now);
	while (!que.empty()) {

		int v = que.front();
		que.pop();
		for (int nxt : g[v]) {
			if (dist[nxt] != IINF) {
				continue;
			}
			prev[nxt] = v;
			dist[nxt] = dist[v] + 1;
			que.push(nxt);
		}
	}

	pii best(IINF, -1);

	for (int i = 0; i < n; i++)
	{
		if (i == now) {
			continue;
		}
		for (int nxt : g[i]) {
			if (nxt == now) {
				best = min(best, pii(dist[i], i));
			}
		}
	}

	if (best.first == IINF) {
	
		return vector<int>(n + 10);
	}
	int to = best.second;
	vector<int> res;
	while (to != -1) {
		res.push_back(to);
		to = prev[to];
	}

	return res;
}


int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int s, t;
		cin >> s >> t;
		s--;
		t--;
		//頂点sから頂点tへの有向辺
		g[s].push_back(t);
	}
	

	vector<int> ans(n + 10);
	for (int i = 0; i < n; i++)
	{
		vector<int> now = bfs(i);
		if (now.size() < ans.size()) {
			ans = now;
		}
	}

	if (ans.size() == n + 10) {
		cout << "-1" << endl;
	}
	else
	{
		cout << ans.size() << endl;
		for (int v : ans) {
			cout << v + 1 << endl;
		}
	}
	
}

