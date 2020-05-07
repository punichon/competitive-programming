#include<algorithm>
#include<bitset>
#include<cassert>
#include<cfloat>
#include<climits>
#include<cmath>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<array>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

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

template <typename T>
bool chmax(T & a, const T & b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
template <typename T>
bool chmin(T & a, const T & b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}


#define ARRAY_MAX 100005
const int INF = 1e9 + 7;
constexpr ll MOD = 1e9 + 7;

int dx4[4] = { 1,0,0,-1 };
int dy4[4] = { 0,1,-1,0 };
int dx2[2] = { 1,0 };
int dy2[2] = { 0,1 };

/******************************************************************************************/
typedef tuple<int,int,int> tpl;

template <typename T> bool next_combination(const T first, const T last, int k) {
    const T subset = first + k;
    // empty container | k = 0 | k == n 
    if (first == last || first == subset || last == subset) {
        return false;
    }
    T src = subset;
    while (first != src) {
        src--;
        if (*src < *(last - 1)) {
            T dest = subset;
            while (*src >= *dest) {
                dest++;
            }
            iter_swap(src, dest);
            rotate(src + 1, dest + 1, last);
            rotate(subset, subset + (last - dest) - 1, last);
            return true;
        }
    }
    // restore
    rotate(first, subset, last);
    return false;
}

//エラトステネスの篩

/*nまでの素数を列挙して配列に保持*/
vector<ll> Eratosthenes(ll n){
    
  	vector<ll> arr(n+1);
    for(ll i = 0; i <= n;i++){
        arr[i] = 1;
    }
	arr[0] = arr[1] = 0;
    for(ll i = 2; i < sqrt(n); i++){
        if(arr[i]){
            for(ll j = 0; i * (j + 2) < n; j++){
                arr[i *(j + 2)] = 0;
            }
        }
    }
    return arr;
}

struct Combination {

	vector<ll> fact, rfact;

	Combination(ll sz) : fact(sz + 1), rfact(sz + 1) {

		fact[0] = 1;
		for (ll i = 1; i < fact.size(); i++) {
			fact[i] = fact[i - 1]%MOD * i % MOD;
		}
		//逆元
		rfact[sz] = inv(fact[sz]);
		for (ll i = sz - 1; i >= 0; i--) {
			rfact[i] = rfact[i + 1] %MOD * (i + 1) % MOD;
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
		if (q < 0 || p < q) return (0LL);
		return (fact[p]%MOD * rfact[q] % MOD * rfact[p - q] % MOD);
	}

	ll H(ll n, ll r) {
		if (n < 0 || r < 0) return (0);
		return (r == 0 ? 1 : C(n + r - 1, r));
	}
};


int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);

	int N;
	cin >> N;
	map<string,int> mp;
	int maxi = 0;
	for(int i = 0;i < N;i++){
		string s;
		cin >> s;
		mp[s]++;
		maxi = max(maxi,mp[s]);
	}

	vector<string> st;
	for(auto itr:mp){
		if(itr.second == maxi){
			st.push_back(itr.first);
		}
	}
	sort(st.begin(),st.end());
	for(int i = 0;i < st.size();i++){
		printf("%s\n",st[i].c_str());
	}





	return 0;
}




