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
typedef pair<int, int> pii;

typedef long long int ll;

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


#define ARRAY_MAX 1005
const ll INF = 1e9 + 7;

int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };

int h, w;
char mp[ARRAY_MAX][ARRAY_MAX];
int cost[ARRAY_MAX][ARRAY_MAX];


int main() {

	cin >> h >> w;
	queue<pii> que;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cost[i][j] = -1;
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> mp[i][j];
			if (mp[i][j] == '#')
			{
				que.push(pii(i, j));
				cost[i][j] = 0;
			}
		}
	}

	while (!que.empty())
	{
		int y = que.front().first;
		int x = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (0 <= nx && nx < w && 0 <= ny && ny < h && mp[ny][nx] == '.' && cost[ny][nx] == -1)
			{
				que.push(pii(ny, nx));
				cost[ny][nx] = cost[y][x] + 1;
			}
		}
	}
	
	int maxi = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			maxi = max(maxi, cost[i][j]);
		}
	}
	cout << maxi << endl;

	return 0;
}



