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

	int n, k;
	cin >> n >> k;
	ll ans = 0;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i <= min(n , k); i++)
	{
		for (int j = 0; i+j <= min(n , k); j++)
		{
			vector<ll> v;
			ll cnt = 0;

			for (int p = 0; p < i; p++)
			{
				v.push_back(a[p]);
				cnt += a[p];
			}
			for (int q = 0; q < j; q++)
			{
				v.push_back(a[n - 1 - q]);
				cnt += a[n - 1 - q];
			}
			sort(v.begin(), v.end());
			
			for (int kk = 0; kk < min(k - i - j,(int)v.size()); kk++)
			{
				
				if (v[kk] < 0) {
					cnt -= v[kk];
				}
				
			}
			ans = max(ans, cnt);
		}
	}
	cout << ans << endl;





	return 0;
}
