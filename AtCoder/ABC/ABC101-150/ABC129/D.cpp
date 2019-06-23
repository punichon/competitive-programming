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

const ll MOD = 1e9 + 7;



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

int r[2055][2055];
int l[2055][2055];
int u[2055][2055];
int d[2055][2055];

char mp[2005][2005];


int main() {

	int h, w;
	cin >> h >> w;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == '#') {
				r[i][j] = 0;
				l[i][j] = 0;
				u[i][j] = 0;
				d[i][j] = 0;
			}
			else
			{
				r[i][j] = 1;
				l[i][j] = 1;
				u[i][j] = 1;
				d[i][j] = 1;
			}
		}
	}

	//右
	for (int i = 0; i < h; i++) {
		for (int j = w-1; j > 0; j--) {

			if (r[i][j - 1] == 0) {
				continue;
			}
			else
			{
				r[i][j - 1] += r[i][j];
			}

		}
	}

	//左
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {

			if (l[i][j + 1] == 0) {
				continue;
			}
			else
			{
				l[i][j + 1] += l[i][j];
			}

		}
	}


	//上
	for (int j = 0; j < w; j++) {
		for (int i = h-1; i > 0; i--) {

			if (u[i - 1][j] == 0) {
				continue;
			}
			else
			{
				u[i - 1][j] += u[i][j];
			}

		}
	}


	//下
	for (int j = 0; j < w; j++) {
		for (int i = 0; i < h; i++) {

			if (d[i + 1][j] == 0) {
				continue;
			}
			else
			{
				d[i + 1][j] += d[i][j];
			}

		}
	}

	int maxi = 0;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++) {

			if (mp[i][j] == '#') {
				continue;
			}

			maxi = max(maxi, r[i][j] + l[i][j] + u[i][j] + d[i][j] - 3);
		}
	}

	cout << maxi << endl;

	return 0;
}
