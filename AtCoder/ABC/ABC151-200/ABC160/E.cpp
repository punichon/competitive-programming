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


template <typename T>
bool chmax(T & a, const T & b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
template <typename T>
bool chmin(T & a, const T & b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}


#define ARRAY_MAX 100005
const int INF = 1e9 + 7;
const ll MOD = 1e9 + 7;

int dx4[4] = { 1,0,0,-1 };
int dy4[4] = { 0,1,-1,0 };
int dx2[2] = { 1,0 };
int dy2[2] = { 0,1 };

/******************************************************************************************/

vector<int> G[2005];

int dist[2005][2005];

vector<int> bfs(int n, int st) {

	vector<int> d(n + 10, INF);
	queue<int> que;
	que.push(st);
	d[st] = 0;

	while (!que.empty()) {

		int now = que.front();
		que.pop();
		if (d[now] == INF)continue;

		for (auto nxt : G[now]) {

			if (d[nxt] > d[now] + 1) {
				d[nxt] = d[now] + 1;
				que.push(nxt);
			}
		}
	}

	return d;
}


int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);

	ll x, y, a, b, c;
	cin >> x >> y >> a >> b >> c;
	vector<ll> p(a), q(b), r(c);

	for (int i = 0; i < a; i++)
	{
		cin >> p[i];
	}

	for (int i = 0; i < b; i++)
	{
		cin >> q[i];
	}

	for (int i = 0; i < c; i++)
	{
		cin >> r[i];
	}

	sort(p.rbegin(), p.rend());
	sort(q.rbegin(), q.rend());
	sort(r.rbegin(), r.rend());

	priority_queue<ll> M;


	for (int i = 0; i < x; i++)
	{
		M.push(p[i]);
	}

	for (int i = 0; i < y; i++)
	{
		M.push(q[i]);
	}

	for (int i = 0; i < c; i++)
	{
		M.push(r[i]);
	}

	ll ans = 0;

	ll cnt = 0;
	while (!M.empty()) {

		ans += M.top();
		M.pop();
		cnt++;
		if (cnt == x + y) {
			break;
		}

	}

	cout << ans << endl;





	return 0;
}

