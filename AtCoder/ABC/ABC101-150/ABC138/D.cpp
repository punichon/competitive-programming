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

vector<vector<int> > G(200005);
int cost[200005];
int flag[200005];
int ans[200005];

void solve(int now, int value) {

	ans[now] = value;
	flag[now] = 1;
    
	for (auto itr : G[now]) {

		if (flag[itr] == 0) {
			solve(itr, value + cost[itr]);
		}
	}
}

int main() {

	int n, q;
	cin >> n >> q;

	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		if (a > b) {
			swap(a, b);
		}

		G[a].push_back(b);
		G[b].push_back(a);
	}

	for (int i = 0; i < q; i++)
	{
		int p, x;
		cin >> p >> x;
		p--;
		cost[p] += x;
	}




	solve(0, cost[0]);


	for (int i = 0; i < n; i++)
	{
		if (i == 0) {
			cout << ans[i];
		}
		else
		{
			cout << " " << ans[i];
		}
	}
	cout << endl;
	return 0;
}
