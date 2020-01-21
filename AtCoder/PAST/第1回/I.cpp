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

ll dp[(1 << 12)];


int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);

	
	int n, m;
	cin >> n >> m;
	vector<string> S(m);
	vector<int> C(m);

	for (int i = 0; i < m; i++)
	{
		cin >> S[i] >> C[i];
		reverse(S[i].begin(), S[i].end());
	}

	for (int i = 0; i < (1<<12); i++)
	{
		dp[i] = LLONG_MAX;
	}

	dp[0] = 0;
	
	for (int i = 0; i < (1<<n); i++)
	{
		//現在の状態がiであるとき
		if (dp[i] == LLONG_MAX) {
			continue;
		}
		for (int j = 0; j < m; j++)
		{
			//cout << "j= " << j << endl;
			//j番目のセットについて探してみる
			ll hoge = 0;
			for (int mask = 0; mask < n; mask++)
			{
				//Yならセットに含まれている
				if (S[j][mask] == 'Y') {
					hoge |= (1LL << mask);
				}
			}

			//hogeとiのORが次の状態

			dp[i | hoge] = min(dp[i | hoge], dp[i] + C[j]);
		}
	}

	if (dp[(1 << n) - 1] == LLONG_MAX) {
		cout << "-1" << endl;
	}
	else
	{
		cout << dp[(1 << n) - 1] << endl;
	}
	


	return 0;
}
