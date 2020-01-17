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
#define ARRAY_MAX 100015

//const int INF = 1e9 + 7;

ll solve(ll a, ll b) {

	if (a > b) {
		swap(a, b);
	}

	if (b % a == 0) {
		return 2 * a*(b / a) - a;
	}
	else {
		return solve(a, b%a) + 2 * a*(b / a);
	}
}


int main() {

	ll n, x;
	cin >> n >> x;
	cout << n + solve(x, n - x) << endl;


	return 0;
}
