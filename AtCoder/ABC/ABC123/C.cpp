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
#include<tuple>
#include<stack>


using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tpl;
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };

#define ARRAY_MAX 100005

const int INF = 1e16 + 7;
const int MOD = 1e9 + 7;

int main() {

	ll n;
	cin >> n;
	vector<ll> a(5);
	ll mini = INF;

	ll index = 0;
	ll maxi = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> a[i];
		maxi = max(maxi, (n - 1) / a[i] + 1);
	}

	cout << maxi + 4 << endl;



	return 0;
}
