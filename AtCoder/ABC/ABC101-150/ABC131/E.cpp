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
const int INF = 1e9 + 7;


int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };

const int MOD = 1e9 + 7;



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
	return (x / tmp) * y;
}


/******************************************************************************************/


int main() {


	ll n, k;
	cin >> n >> k;
	

	if (k > (n - 1)*(n - 2) / 2) {
		cout << "-1" << endl;
	}
	else
	{
		int ans = (n - 1)*(n - 2) / 2;
		set<pii> st;
		for (int i = 2; i <= n; i++)
		{
			st.insert(pii(1, i));
		}
		while (ans != k) {

			for (int i = 2; i <= n; i++)
			{
				bool flag = true;
				for (int j = i + 1; j <= n; j++) {
					if (st.find(pii(i, j)) == st.end()) {
						st.insert(pii(i, j));
						ans--;
						if (ans == k) {
							flag = false;
							break;
						}
					}
				}
				if (!flag) {
					break;
				}
			}
		}
		cout << st.size() << endl;
		for (auto itr : st) {
			cout << itr.first << " " << itr.second << endl;
		}
	}




	return 0;
}
