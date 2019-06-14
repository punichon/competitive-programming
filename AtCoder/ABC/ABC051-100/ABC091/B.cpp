#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#include<climits>
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
typedef pair<ll, ll> pll;
//int dx[4] = { 1,0,0,-1 };
//int dy[4] = { 0,1,-1,0 };
#define MOD 1000000007
#define ARRAY_MAX 100005

const int INF = 1e9 + 7;




int main() {


	ios::sync_with_stdio(false);
	cin.tie(0);

	map<string, int> mp;
	int n, m;
	cin >> n;
	for (int i = 0; i < n ; i++)
	{
		string s;
		cin >> s;
		mp[s]++;
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		string t;
		cin >> t;
		mp[t]--;
	}
	
	int ans = 0;
	for (auto itr : mp)
	{
		if (itr.second > 0) {
			ans = max(ans, itr.second);
		}
	}
	cout << ans << endl;

	return 0;
}
