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

	ll m, k;
	cin >> m >> k;


	if (m == 0)
	{
		if (k == 0)
		{
			cout << "0 0" << endl;
		}
		else
		{
			cout << "-1" << endl;
		}
		return 0;
	}

	if (m == 1)
	{
		if (k != 0)
		{
			cout << "-1" << endl;
		}
		else
		{
			cout << "0 0 1 1" << endl;

		}
		return 0;
	}

	if (k >= (1LL << m)) {
		cout << "-1" << endl;
		return 0;
	}

	vector<ll> ans;
	ll maxi = 1LL << m;

	for (ll i = 0; i < maxi; i++)
	{
		if (i != k)
		{
			ans.push_back(i);
		}
	}
	ans.push_back(k);

	for (ll i = maxi - 1; i >= 0; i--)
	{
		if (i != k)
		{
			ans.push_back(i);
		}
	}
	ans.push_back(k);

	for (int i = 0; i < ans.size(); i++)
	{
		if (i == 0)
		{
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
