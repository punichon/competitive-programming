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

#define ARRAY_MAX 100005
const ll INF = 1e9;
const ll MOD = 1e9 + 7;

int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };




/******************************************************************************************/


ll dp[100005][15];

int main() {

	
	string s;
	cin >> s;

	dp[0][0] = 1LL;

	for (int i = 0; i < s.size(); i++)
	{
		int num = -1;
		if (s[i] == '?') {
			num = -1;
		}
		else
		{
			num = s[i] - '0';
		}

		for (int j = 0; j < 10; j++)
		{
			//余り
			if (num != -1 && num != j)continue; //numが-1なら全部試す、-1でないならnum==jとなるjのみを試す

			for (int k = 0; k < 13; k++)
			{
				dp[i + 1][(k * 10 + j) % 13] += dp[i][k];
			}
		}

		for (int j = 0; j < 13; j++)
		{
			dp[i + 1][j] %= MOD;
		}
	}

	cout << dp[s.size()][5] << endl;

	return 0;
}
