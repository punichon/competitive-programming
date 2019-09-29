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


//約数の列挙
template<typename T>
vector<T> divisor(T n) {
	vector<T> res;
	for (T i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			res.push_back(i);
			if (i != n / i) {
				res.push_back(n / i);
			}
		}
	}
	return res;
}


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

/*最小公倍数*/
template<typename T>
T lcm(T x, T y) {
	T tmp = gcd(x, y);
	return x * y / tmp;
}

//素数判定
bool is_prime(ll n) {
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return n != 1;//1の場合は除外
}


int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	ll A, B;
	cin >> A >> B;

	vector<ll> hoge = divisor(A);
	vector<ll> hoge2 = divisor(B);
	
	set<ll> st1, st2;
	for (int i = 0; i < hoge.size(); i++)
	{
		st1.insert(hoge[i]);
	}
	for (int i = 0; i < hoge2.size(); i++)
	{
		st1.insert(hoge2[i]);
	}

	vector<ll> v;
	for (auto itr : st1) {
		if (A % itr == 0 && B % itr == 0) {
			v.push_back(itr);
		}
	}

	ll ans = 1;

	

	for (int i = 0; i < v.size(); i++)
	{
		if (is_prime(v[i])) {
			ans++;
		}
	}

	cout << ans << endl;
}

