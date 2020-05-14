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

ll modPow(long long a, long long n, long long p) {
  if (n == 1) return a % p;
  if (n % 2 == 1) return (a * modPow(a, n - 1, p)) % p;
  long long t = modPow(a, n / 2, p);
  return (t * t) % p;
}

long long pow(long long a,long long n){
  long long ret=1;
  for(;n>0;n>>=1,a=a*a%MOD){
    if(n%2==1){
      ret=ret*a%MOD;

    }
  }
  return ret;
}
// a^-1
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);

	ll n,a,b;
	cin >> n >> a >> b;
	ll hoge = modPow(2,n,MOD)-1;//nC0を除くために-1

	//nCaを引く

	ll denominator = 1LL;//分母
	ll Numerator = 1LL;//分子

	ll up = n;
	ll bt = a;
	for (int i = 0; i < a; i++)
	{
		denominator *= bt;
		denominator %= MOD;
		bt--;
		Numerator *= up;
		Numerator %= MOD;
		up--;
	}
	denominator = modinv(denominator,MOD);

	hoge -= Numerator*denominator%MOD;
	hoge = (hoge+MOD)%MOD;
	hoge %= MOD;
	
	//nCbを引く
    
	denominator = 1LL;
	Numerator = 1LL;
	up = n;
	bt = b;
	for (int i = 0; i < b; i++)
	{
		denominator *= bt;
		denominator %= MOD;
		bt--;
		Numerator *= up;
		Numerator %= MOD;
		up--;
	}

	denominator = modinv(denominator,MOD);

	hoge -= Numerator*denominator%MOD;
	
	hoge = (hoge+MOD)%MOD;

	cout << hoge << endl;


	return 0;
}




