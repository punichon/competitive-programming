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
typedef pair<int, int> pii;

typedef long long int ll;



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



//ユークリッド互除法
template<typename T>
T gcd(T x, T y) {

	if (y == 0) {
		return x;
	}
	else {
		return gcd(y, x % y);
	}
}

ll le[ARRAY_MAX];
ll ri[ARRAY_MAX];

int main() {

	ll n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	le[0] = a[0];
	ri[n - 1] = a[n - 1];

	for (int i = 1; i < n; i++)
	{
		le[i] = gcd(le[i - 1], a[i]);
	}


	for (int i = n - 2; i >= 0; i--)
	{
		ri[i] = gcd(ri[i + 1], a[i]);
	}

	ll maxi = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			maxi = max(maxi, ri[i + 1]);
		}
		else if (i == n - 1)
		{
			maxi = max(maxi, le[i - 1]);
		}
		else
		{
			maxi = max(maxi, gcd(ri[i + 1], le[i - 1]));
		}
	}
	cout << maxi << endl;
}



