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
typedef tuple<ll, ll, ll> tpl;


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
const int INF = 1e9;
const ll MOD = 1e9 + 7;

int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };




/******************************************************************************************/



//素数判定
bool is_prime(ll n) {
	for (ll i = 2; i*i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return n != 1;//1の場合は除外
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

int check[200005];
vector<pii> V[200005];



int main() {

	int n;
	cin >> n;
	vector<int> cnt(n+ 10, 0);
	vector<int> a(n), b(n), c(n);
	for (int i = 0; i < n - 2; i++)
	{
		cin >> a[i] >> b[i] >> c[i];
		cnt[a[i]]++;
		cnt[b[i]]++;
		cnt[c[i]]++;
		V[a[i]].push_back(pii(b[i], c[i]));
		V[b[i]].push_back(pii(a[i], c[i]));
		V[c[i]].push_back(pii(a[i], b[i]));
	}

	vector<int> st;
	int siz = 0;
	vector<int> ans;

	bool flag = true;
	for (int i = 1; i <= n; i++)
	{
		if (cnt[i] == 1) {
			for (auto itr : V[i]) {

				if (cnt[itr.first] == 2 || cnt[itr.second] == 2) {
					ans.push_back(i);
					check[i] = 1;
					check[itr.first] = 1;
					check[itr.second] = 1;
					if (cnt[itr.first] < cnt[itr.second]) {
						ans.push_back(itr.first);
						ans.push_back(itr.second);
					}
					else
					{
						ans.push_back(itr.second);
						ans.push_back(itr.first);
					}
					flag = false;
					break;
				}
			}
		
		}
		if (!flag) {
			break;
		}
	}

	while (ans.size() < n) {

		for (auto itr : V[ans[ans.size()-2]]) {

			if (check[itr.first] == 1 && check[itr.second] ==1)continue;
			
			if (check[itr.first] == 1) {
				ans.push_back(itr.second);
				check[itr.second] = 1;
			}
			else
			{
				ans.push_back(itr.first);
				check[itr.first] = 1;
			}
			break;
		}
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

	
	return 0;
}