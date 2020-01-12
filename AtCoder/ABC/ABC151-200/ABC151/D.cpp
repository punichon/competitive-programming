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


// aよりもbが大きいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmax(T& a, const T& b) {
	if (a < b) {
		a = b;  // aをbで更新
		return true;
	}
	return false;
}
// aよりもbが小さいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmin(T& a, const T& b) {
	if (a > b) {
		a = b;  // aをbで更新
		return true;
	}
	return false;
}


#define ARRAY_MAX 100005
const int INF = INT32_MAX / 3;
const ll MOD = 1e9 + 7;

int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };


/******************************************************************************************/





char mp[30][30];
int dist[30][30];

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);

	int h, w;
	cin >> h >> w;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> mp[i][j];
		}
	}


	int maxi = 0;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{

			//初期か
			for (int a = 0; a < h; a++)
			{
				for (int b = 0; b < w; b++)
				{
					dist[a][b] = INF;
				}
			}

			//壁なら何もしない
			if (mp[i][j] == '#') {
				continue;
			}

			dist[i][j] = 0;

			queue<pii> que;
			que.push(pii(i, j));

			//i,j,はすでに使用

			while (!que.empty()) {

				int nowy = que.front().first;
				int nowx = que.front().second;
				que.pop();
				//cout << "nowy " << nowy << " nowx= " << nowx << endl;
				for (int A = 0; A < 4; A++)
				{
					int ny = nowy + dy[A];
					int nx = nowx + dx[A];

					if (0 <= ny && ny < h && 0 <= nx && nx < w && mp[ny][nx] != '#') {

						if (dist[ny][nx] > dist[nowy][nowx] + 1) {
							dist[ny][nx] = dist[nowy][nowx] + 1;
							//cout << "dd " << dist[ny][nx] << endl;
							que.push(pii(ny, nx));
						}
					}
				}
			}

			//初期か
			for (int a = 0; a < h; a++)
			{
				for (int b = 0; b < w; b++)
				{
					if (dist[a][b] == INF) {
						continue;
					}
					maxi = max(maxi, dist[a][b]);
				}
			}

		}

	}

	cout << maxi << endl;


	return 0;
}

