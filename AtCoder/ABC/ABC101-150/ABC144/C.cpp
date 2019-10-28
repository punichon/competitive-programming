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
#include<bitset>
#include<stack>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define repi(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> lltpl;

int dy8[8] = { 2,2,-2,-2,1,1,-1,-1 };
int dx8[8] = { 1,-1,1,-1,2,-2,2,-2 };
int dx4[4] = { 1,0,0,-1 };
int dy4[4] = { 0,1,-1,0 };


/******************************************************************************************/


const int IINF = 1e9 + 7;
const ll LINF = LLONG_MAX;
constexpr ll MOD = 1e9 + 7;



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

// vector
template <typename T>
istream& operator>>(istream & is, vector<T> & vec) { for (T& x : vec) is >> x; return is; }
// pair
template <typename T, typename U>ostream& operator<<(ostream & os, pair<T, U> & pair_var) { os << "(" << pair_var.first << ", " << pair_var.second << ")"; return os; }
// vector
template <typename T>ostream& operator<<(ostream & os, const vector<T> & vec) { os << "{";	for (int i = 0; i < vec.size(); i++) { os << vec[i] << (i + 1 == vec.size() ? "" : ", "); }os << "}"; return os; }
// map
template <typename T, typename U>ostream& operator<<(ostream & os, map<T, U> & map_var) { os << "{";	repi(itr, map_var) { os << *itr; itr++; if (itr != map_var.end()) os << ", "; itr--; }os << "}"; return os; }
// set
template <typename T>ostream& operator<<(ostream & os, set<T> & set_var) { os << "{"; repi(itr, set_var) { os << *itr; itr++; if (itr != set_var.end()) os << ", "; itr--; }os << "}"; return os; }


struct Combination {

	vector<ll> fact, rfact;

	Combination(ll sz) : fact(sz + 1), rfact(sz + 1) {

		fact[0] = 1;
		for (ll i = 1; i < fact.size(); i++) {
			fact[i] = fact[i - 1] * i % MOD;
		}
		//逆元
		rfact[sz] = inv(fact[sz]);
		for (ll i = sz - 1; i >= 0; i--) {
			rfact[i] = rfact[i + 1] * (i + 1) % MOD;
		}
	}

	ll inv(ll x) {
		return pow(x, MOD - 2);
	}
	ll pow(ll x, ll n) {
		ll ret = 1;
		while (n > 0) {
			if (n & 1) (ret *= x) %= MOD;
			(x *= x) %= MOD;
			n >>= 1;
		}
		return (ret);
	}
	ll P(ll n, ll r) {
		if (r < 0 || n < r) return (0);
		return (fact[n] * rfact[n - r] % MOD);
	}

	ll C(ll p, ll q) {
		if (q < 0 || p < q) return (0);
		return (fact[p] * rfact[q] % MOD * rfact[p - q] % MOD);
	}

	ll H(ll n, ll r) {
		if (n < 0 || r < 0) return (0);
		return (r == 0 ? 1 : C(n + r - 1, r));
	}
};



int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	
	ll n;
	cin >> n;
	ll ans = LINF;
	for (ll i = 1; i*i <= n; i++)
	{
		if (n % i == 0) {
			ans = min(ans, i - 1 + n / i - 1);
		}
	}


	cout << ans << endl;




	
	return 0;
}
