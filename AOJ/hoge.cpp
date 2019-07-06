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
const ll MOD = 1e9 + 7;

int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };


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
		//modpow
		return pow(x, MOD - 2);
	}
	ll pow(ll x, ll n) {
		//累乗
		ll ret = 1;
		while (n > 0) {
			if (n & 1) (ret *= x) %= MOD;
			(x *= x) %= MOD;
			n >>= 1;
		}
		return (ret);
	}
	ll P(ll n, ll r) {
		//順列
		if (r < 0 || n < r) return (0);
		return (fact[n] * rfact[n - r] % MOD);
	}

	ll C(ll p, ll q) {
		//組み合わせ
		if (q < 0 || p < q) return (0);
		return (fact[p] * rfact[q] % MOD * rfact[p - q] % MOD);
	}

	ll H(ll n, ll r) {
		//重複組み合わせ
		if (n < 0 || r < 0) return (0);
		return (r == 0 ? 1 : C(n + r - 1, r));
	}
};


/******************************************************************************************/

bool isalpha(char c) {

	if (0 <= c - 'A' && c - 'A' < 26) {
		return true;
	}
	else
	{
		return false;
	}

}

string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int idx = 0;
string s;
int siz = 0;

string solve(string& s) {

	string tmp;
	int cnt = 0;
	while (idx < siz) {

		if (s[idx] == '+') {
			cnt++;
			idx++;
		}

		if (s[idx] == '-') {
			cnt--;
			idx++;
		}

		if (isalpha(s[idx])) {
			int hoge = (s[idx] - 'A' + 26 + cnt) % 26;
			tmp.push_back(alpha[hoge]);
			cnt = 0;
			idx++;
		}

		if (s[idx] == '?') {
			tmp.push_back('*');
			cnt = 0;
			idx++;
		}
		
		if (s[idx] == '[') {
			idx++;
			tmp += solve(s);
		}
		
		if (s[idx] == ']') {
			idx++;
			reverse(tmp.begin(), tmp.end());
			return tmp;
		}
	}

	return tmp;
}

int main() {

	while(cin >> s,s != "."){
		idx = 0;
		siz = s.size();
		string ans = solve(s);
		for (int i = 0; i < ans.size(); i++)
		{
			if (ans[i] == '*') {
				ans[i] = 'A';
			}
		}
		cout << ans << endl;
		ans.clear();
		s.clear();
	}

	return 0;
}
