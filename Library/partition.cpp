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

//基準となるあるxに対して，x以下の領域，xより大きい領域に分割 O(n)
int partition(vector<int>& a, int p, int r) {

	int x, i, j, t;

	x = a.back();
	i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (a[j] <= x) {
			i++;
			swap(a[i], a[j]);

		}
	}


	return i;
}


int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	int q = partition(a, 0, n);

	for (int i = 0; i < n; i++)
	{
		if (i)cout << " ";
		if (i == q) {
			cout << '[';
		}
		cout << a[i];
		if (i == q) {
			cout << ']';
		}
	}
	cout << endl;
	


	return 0;
}
