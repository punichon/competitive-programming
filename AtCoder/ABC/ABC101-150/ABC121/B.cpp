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

	int n, m, c;
	cin >> n >> m >> c;
	int b[ARRAY_MAX];
	int a[ARRAY_MAX][ARRAY_MAX];
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < m; j++) {
			cnt += a[i][j] * b[j];
		}
		//cout << "cnt=" << cnt << endl;
		if (cnt + c > 0) {
			ans++;
		}
	}
	cout << ans << endl;




	return 0;
}
