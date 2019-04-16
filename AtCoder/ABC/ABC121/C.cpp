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
#define ARRAY_MAX 50

const int INF = 1e9 + 7;


int main() {


	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, m;
	cin >> n >> m;
	vector<pll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	ll cnt = 0;//本数
	sort(a.begin(), a.end());

	
	ll ans = 0;//金
	for (int i = 0; i < n; i++) {
		//cout << "cnt = " << cnt << endl;
		if (cnt + a[i].second < m) {
			//cout << "a" << endl;
			ans += a[i].first*a[i].second;
			cnt += a[i].second;
		}
		else {
			//cout << "b" << endl;
			while (cnt < m) {
				cnt++;
				ans += a[i].first;
			}
		}
		//cout << i << " " << cnt << " " << ans << endl;
		if (cnt == m) {
			break;
		}
	}

	cout << ans << endl;






	return 0;
}
