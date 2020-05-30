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
const ll MOD = 1e9 + 7;

int dx4[4] = { 1,0,0,-1 };
int dy4[4] = { 0,1,-1,0 };
int dx2[2] = { 1,0 };
int dy2[2] = { 0,1 };

/******************************************************************************************/

char mp[15][1005];


int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);

	int h, w, k;
	cin >> h >> w >> k;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> mp[i][j];
		}
	}

	int ans = INF;
	for (int mask = 0; mask < (1 << (h - 1)); mask++)
	{
		vector<vector<int> > comp;
		vector<int> hoge(w + 10, 0);
		int cnt = 0;
		bool can = true;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				hoge[j + 1] += mp[i][j] - '0';
			}

			if ((mask >> i) & 1) {
				//ここで線が入る
				for (int j = 0; j <= w; j++)
				{
					if (hoge[j] > k) {
						can = false;
						break;
					}
				}

				if (!can)break;
				comp.push_back(hoge);
				fill_v(hoge, 0);
				cnt++;
			}
		}

		for (int j = 0; j <= w; j++)
		{
			if (hoge[j] > k) {
				can = false;
				break;
			}
		}
		if (!can)continue;
		
		comp.push_back(hoge);


		//あとは左から貪欲
		for (int j = 0; j < w; j++)
		{
			bool ok = true;
			for (int i = 0; i < comp.size(); i++)
			{
				ok &= (comp[i][j] + comp[i][j + 1] <= k);
			}


			if (ok) {
				for (int i = 0; i < comp.size(); i++)
				{
					comp[i][j + 1] += comp[i][j];
				}
			}
			else
			{
				cnt++;
			}
		}
		ans = min(ans, cnt);
	}


	cout << ans << endl;







	return 0;
}

