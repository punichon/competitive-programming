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
#define ARRAY_MAX 55

const int INF = 1e9 + 7;



int main() {


	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pii> x(n);
	vector<int> ans(n);
	for (int i = 0; i < n; i++)
	{
		cin >> x[i].first;
		x[i].second = i;
	}

	sort(x.begin(), x.end());

	for (int i = 0; i < n; i++) {
		//cout << x[i].first << " " << x[i].second << endl;
		if (i < n/2) {
			ans[x[i].second] = x[n / 2].first;
		}
		else {
			ans[x[i].second] = x[n / 2 - 1].first;
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}
