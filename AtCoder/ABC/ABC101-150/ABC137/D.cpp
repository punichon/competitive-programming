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


bool comp(const pii& a, const pii& b) {

	if (a.first == b.first) {
		return a.second > b.second;
	}
	else
	{
		return a.first < b.first;
	}
}


int main() {

	int n, m;
	cin >> n >> m;
	priority_queue<int> que;

	vector<pii> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end(), comp);

	int idx = 0;
	int ans = 0;

	for (int i = m; i >= 0; i--)
	{
		//残りi日ある（i日前）

		while (idx < n && v[idx].first + i <= m) {
			que.push(v[idx].second);
			idx++;
		}
		if (!que.empty()) {
			ans += que.top();
			que.pop();
		}
	}

	cout << ans << endl;









	return 0;
}
