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
const ll INF = 1e9 + 7;


int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };

const ll MOD = 1e9 + 7;



int main() {


	ll n, m;
	cin >> n >> m;
	
	priority_queue<ll, vector<ll>, greater<ll> > que;

	for (int i = 0; i < n; i++)
	{
		ll tmp;
		cin >> tmp;
		que.push(tmp);
	}

	vector<pll> query(m);
	for (int i = 0; i < m; i++)
	{
		cin >> query[i].first >> query[i].second;
	}
	sort(query.begin(), query.end(), greater<pll>());


	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < query[i].first; j++)
		{
			ll tmp = que.top();
			if (tmp < query[i].second)
			{
				que.pop();
				que.push(query[i].second);
			}
			else
			{
				break;
			}
		}
	}

	ll ans = 0;
	while (!que.empty())
	{
		ans += que.top();
		que.pop();
	}
	cout << ans << endl;

	return 0;
}
