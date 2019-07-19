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
using namespace std;

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define VSORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)


typedef long long ll;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


/*************************************************************************/
//多次元配列の確保及び初期化用マクロ
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
/*************************************************************************/


#define ARRAY_MAX 100005
const ll INF = 1e9 + 7;
const ll MOD = 1e9 + 7;

int main() {

	ll h, w;
	cin >> h >> w;
	ll ans = 1e15;
	//横横
	for (ll i = 1; i <= h - 2 ; i++)
	{
		ll s1 = i * w;
		ll s2 = (h - i) / 2 * w;
		ll s3 = h * w - s1 - s2;
		ll maxi = max(s1, max(s2, s3));
		ll mini = min(s1, min(s2, s3));
		ans = min(ans, maxi - mini);
	}
	
	//縦縦
	for (ll i = 1; i <= w - 2; i++)
	{
		ll s1 = i * h;
		ll s2 = (w - i) / 2 * h;
		ll s3 = h * w - s1 - s2;
		ll maxi = max(s1, max(s2, s3));
		ll mini = min(s1, min(s2, s3));
		ans = min(ans, maxi - mini);
	}

	//横縦
	for (ll i = 1; i <= h - 1; i++)
	{
		ll s1 = i * w;
		ll s2 = (h - i) * (w/2);
		ll s3 = h * w - s1 - s2;
		ll maxi = max(s1, max(s2, s3));
		ll mini = min(s1, min(s2, s3));
		ans = min(ans, maxi - mini);
	}


	//縦横
	for (ll i = 1; i <= w - 1; i++)
	{
		ll s1 = i * h;
		ll s2 = (w - i) * (h / 2);
		ll s3 = h * w - s1 - s2;
		ll maxi = max(s1, max(s2, s3));
		ll mini = min(s1, min(s2, s3));
		ans = min(ans, maxi - mini);
	}

	cout << ans << endl;


	return 0;
}
