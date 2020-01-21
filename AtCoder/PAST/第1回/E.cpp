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




const int INF = 1e9 + 7;


/******************************************************************************************/

char ans[105][105];


int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);


	int n, q;
	cin >> n >> q;

	for (int i = 0; i < 105; i++)
	{
		for (int j = 0; j < 105; j++)
		{
			ans[i][j] = 'N';
		}
	}



	for (int i = 0; i < q; i++)
	{
		int c;
		cin >> c;
		if (c == 1) {

			int a, b;
			cin >> a >> b;
			ans[a][b] = 'Y';

		}
		else if (c == 2) {

			int a;
			cin >> a;

			for (int j = 1; j <= n; j++)
			{
				if (j == a)continue;
				if (ans[j][a] == 'Y') {
					ans[a][j] = 'Y';
				}
			}
		}
		else
		{
			int a;
			cin >> a;
			vector<int> v;

			for (int j = 1; j <= n; j++)
			{
				if (j == a)continue;
				if (ans[a][j] == 'Y') {
					v.push_back(j);
				}
			}

			for (int j = 0; j < v.size(); j++)
			{
				int to = v[j];

				for (int k = 1; k <= n; k++)
				{
					if (k == a)continue;
					if (ans[to][k] == 'Y') {
						ans[a][k] = 'Y';
					}

				}

			}

		
		}
	}


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << ans[i][j];
		}
		cout << endl;
	}

	return 0;
}
