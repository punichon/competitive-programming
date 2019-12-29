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
#include<complex>
#include<list>
#include<cstdio>

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




const int INF = 1e9+7;


/******************************************************************************************/
//verify:AOJ ALDS1_7_B

vector<int> G[100005];
int pa[100005];
int d[100005];
int in[100005];
int h[100005];
int sib[100005];

int dfs(int par, int now, int dpt) {


	pa[now] = par;
	d[now] = dpt;

	int height = -1;

	if (G[now].size() > 0) {

		int left = 0;
		int right = 0;

		if (G[now].size() == 1) {
			left = G[now][0];
			sib[left] = -1;

			if (pa[left] == -INF) {
				height = max(height, dfs(now, left, dpt + 1));
			}
		}
		else {
			left = G[now][0];
			right = G[now][1];

			sib[left] = right;
			sib[right] = left;

			if (pa[left] == -INF) {
				height = max(height, dfs(now, left, dpt + 1));
			}
			if (pa[right] == -INF) {
				height = max(height, dfs(now, right, dpt + 1));
			}
		}
	
	}
	return h[now] = height + 1;
}



int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int v, l, r;
		cin >> v >> l >> r;

		if (l != -1) {
			G[v].push_back(l);
			in[l]++;
		}
		if (r != -1) {
			G[v].push_back(r);
			in[r]++;
		}
	}

	for (int i = 0; i < 100005; i++)
	{
		pa[i] = -INF;
		sib[i] = -1;
	}

	int node = 0;

	//親を探す
	for (int i = 0; i < 100005; i++)
	{
		if (in[i] == 0) {
			node = i;
			break;
		}
	}

	dfs(-1, node, 0);//（親番号，今いる番号，深さ）

	for (int i = 0; i < n; i++)
	{
		cout << "node " << i << ": parent = " << pa[i] << ", sibling = " << sib[i] << ", degree = " << G[i].size() << ", depth = " << d[i] << ", height = " << h[i];
		
	
		if (d[i] == 0) {
			cout << ", root";
		}else if (G[i].size() == 0) {
			cout << ", leaf";
		}
		else
		{
			cout << ", internal node";
		}
	
		cout << endl;
	}


	return 0;
}
