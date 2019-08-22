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



int main() {

	
	int n, cnt = 0;
	cin >> n;
	vector<int> a(n+10);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (i != a[i]) {
			cnt++;
		}
	}

	if (cnt <= 2) {
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}



	return 0;
}
