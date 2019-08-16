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


int main() {

	ll n, q;
	cin >> n >> q;

	vector<ll> s(n), t(n), x(n), d(q);

	for (int i = 0; i < n; i++)
	{
		scanf("%lld %lld %lld", &s[i], &t[i], &x[i]);
	}
	for (int i = 0; i < q; i++)
	{
		scanf("%lld", &d[i]);
	}

	vector<pair<pll, ll> > events;//(時刻，座標，フラグ)
	set<ll> cannot_use;

	for (int i = 0; i < n; i++)
	{
		events.push_back(make_pair(make_pair(s[i] - x[i], x[i]), 1));
		events.push_back(make_pair(make_pair(t[i] - x[i], x[i]), 0));
	}

	sort(events.begin(), events.end());

	int idx = 0;
	int siz = events.size();

	for (int i = 0; i < q; i++)
	{
		while (idx < siz && events[idx].first.first <= d[i]) {

			if (events[idx].second == 1) {
				//工事の開始
				cannot_use.insert(events[idx].first.second);
			}
			else
			{
				//工事の終了
				cannot_use.erase(events[idx].first.second);
			}
			idx++;
		}
		if (cannot_use.empty()) {
			cout << "-1" << endl;
		}
		else
		{
			cout << *cannot_use.begin() << '\n';
		}
	}
	

	return 0;
}
