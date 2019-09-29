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

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	

	int n;
	cin >> n;
	vector<pii> a(n);
	vector<int> ans(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	sort(a.begin(), a.end());

	for (int i = 0; i < n; i++)
	{
		ans[i] = a[i].second;
	}


	

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



	

}

