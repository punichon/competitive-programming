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


#define ARRAY_MAX 100005
const ll INF = 1e9 + 7;


int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };

struct node {

	ll to;
	ll cost;

};

vector<node> G[ARRAY_MAX];
int n;
bool used[ARRAY_MAX];
int co[ARRAY_MAX];

void dfs(int now, int color)
{

	//cout << "now = " << now << "color = " << color << endl;
	used[now] = 1;
	co[now] = color;

	bool all_visited = true;

	for (int i = 0; i < n; i++)
	{
		if (used[i] == false)
		{
			all_visited = false;
			break;
		}
	}

	//cout << "a" << endl;
	if (all_visited)
	{
		return;
	}

	//cout << "b" << endl;
	for (int i = 0;i < G[now].size();i++)
	{
		if (used[G[now][i].to] == true)
		{
			continue;
		}

		//cout << "cost = " << G[now][i].cost << endl;
		if (G[now][i].cost % 2)
		{
			//cout << "c" << endl;
			dfs(G[now][i].to, 1 - color);
		}
		else
		{
			dfs(G[now][i].to, color);
		}
	}
}

int main() {

	cin >> n;
	for (int i = 0; i < n-1; i++)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		G[a].push_back(node{ b,c });
		G[b].push_back(node{ a,c });
	}


	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < G[i].size(); j++)
		{
			cout << G[i][j].to << " ";
		}
		cout << endl;
	}*/

	dfs(0,0);

	for (int i = 0; i < n; i++)
	{
		cout << co[i] << endl;
	}

	return 0;
}

