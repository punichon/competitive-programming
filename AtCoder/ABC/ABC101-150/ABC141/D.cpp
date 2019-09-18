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

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tpl;


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
const int INF = 1e9;
const ll MOD = 1e9 + 7;

int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };




/******************************************************************************************/


int main() {

	
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n);
	priority_queue<tpl> que;
	vector<ll> po(100);

	ll hoge = 1LL;
	for (int i = 0; i < 36; i++)
	{
		po[i] = hoge;
		hoge *= 2LL;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		que.push(tpl(a[i], a[i], 0LL));
	}

	for (int i = 0; i < m; i++)
	{
		tpl tapi = que.top();
		que.pop();
		ll a, b, c;
		tie(a, b, c) = tapi;
		if (a == 0) {
			break;
		}
		que.push(tpl(b / (po[c+1]), b, c + 1));
	}

	ll ans = 0;
	while (!que.empty()) {
		tpl tapi = que.top();
		que.pop();
		ll a, b, c;
		tie(a, b, c) = tapi;
		ans += a;
	}

	cout << ans << endl;


	


	return 0;
}
