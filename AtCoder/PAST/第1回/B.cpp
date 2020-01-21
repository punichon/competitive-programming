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




const int INF = 1e9+7;


/******************************************************************************************/


int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);


	int n;
	cin >> n;
	vector<int> a(n + 10);
	for (int i = 0; i < n ; i++)
	{
		cin >> a[i];
	}


	for (int i = 1; i < n; i++)
	{
		if (a[i] == a[i - 1]) {
			cout << "stay" << endl;
		}
		else if (a[i] > a[i - 1]) {
			cout << "up " << a[i] - a[i - 1] << endl;
		}
		else
		{
			cout << "down " << a[i - 1] - a[i] << endl;
		}
	}


	return 0;
}
