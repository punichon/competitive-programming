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
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };
#define MOD 1000000007
#define ARRAY_MAX 100005

//const int INF = 1e9 + 7;

int main() {

	ll n, x;
	cin >> n >> x;
	vector<pll> a(ARRAY_MAX);
	vector<ll> b(ARRAY_MAX,0);

	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i].first;
		b[i] = a[i].first;
		a[i].second = i;
	}
	//番兵
	b[0] = 0;
	b[n + 1] = 0;

	sort(a.begin(), a.end(), greater<pll>());

	vector<ll> ans;

	for (ll i = 0; i < n; i++)
	{
		ll index = a[i].second;
		ll num = a[i].first;
		if (b[index] + b[index + 1] >= x)
		{
			for (ll j = index; j < n; j++)
			{
				ans.push_back(j);
			}
			for (ll j = index - 1; j >= 1; j--)
			{
				ans.push_back(j);
			}
			break;
		}
		else if (b[index] + b[index-1] >= x)
		{
			for (ll j = index - 1; j >= 1; j--)
			{
				ans.push_back(j);
			}
			for (ll j = index; j < n; j++)
			{
				ans.push_back(j);
			}
			break;
		}
	}
	
	if (ans.size() > 0)
	{
		cout << "Possible" << endl;
		for (ll i = ans.size()-1; i >= 0; i--)
		{
			cout << ans[i] << endl;
		}
	}
	else {
		cout << "Impossible" << endl;
	}


	return 0;
}
