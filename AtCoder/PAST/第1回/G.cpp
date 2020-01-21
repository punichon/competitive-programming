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


int v[20][20];
int len[20];

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);

	
	int n;
	cin >> n;
	int loopmaxi = pow(3, n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = i+1; j <= n; j++)
		{
			cin >> v[i][j];
			v[j][i] = v[i][j];
		}
	}



	ll maxi = -INF;

	for (int mask = 0; mask < loopmaxi; ++mask) {
		int tmp = mask;
		vector<int> a, b, c;

		ll sum = 0;
		for (int pos = 1; pos <= n; ++pos) {//数字1~kが何文字分か仮定する
			len[pos] = tmp % 3;//どのグループに入るか
			tmp /= 3;
		}

		//グループ分けをする

		for (int i = 1; i <= n; i++)
		{
			if (len[i] == 0) {
				a.push_back(i);
			}
			if (len[i] == 1) {
				b.push_back(i);
			}
			if (len[i] == 2) {
				c.push_back(i);
			}
		}

		for (int i = 0; i < a.size(); i++)
		{
			int one = a[i];
			for (int j = i + 1; j < a.size(); j++)
			{
				int other = a[j];
				sum += v[one][other];
			}
		}

		for (int i = 0; i < b.size(); i++)
		{
			int one = b[i];
			for (int j = i + 1; j < b.size(); j++)
			{
				int other = b[j];
				sum += v[one][other];
			}
		}

		for (int i = 0; i < c.size(); i++)
		{
			int one = c[i];
			for (int j = i + 1; j < c.size(); j++)
			{
				int other = c[j];
				sum += v[one][other];
			}
		}


		maxi = max((ll)maxi, (ll)sum);
	}

	cout << maxi << endl;

	return 0;
}
