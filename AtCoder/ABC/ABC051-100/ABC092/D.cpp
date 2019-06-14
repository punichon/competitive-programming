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

	int a, b;
	cin >> a >> b;
	char mp[105][105];

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (i < 50) {
				mp[i][j] = '#';//黒
			}
			else {
				mp[i][j] = '.';//白
			}
		}
	}

	int black = 1, white = 1;
	
	for (int i = 0; i < 50; i+= 2)
	{
		for (int j = 0; j < 100; j+=2)
		{
			if (white < a) {
				mp[i][j] = '.';
				white++;
			}
		}
	}
	
	for (int i = 51; i < 100; i += 2)
	{
		for (int j = 0; j < 100; j += 2)
		{
			if (black < b) {
				mp[i][j] = '#';
				black++;
			}
		}
	}

	cout << "100 100" << endl;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			cout << mp[i][j];
		}
		cout << endl;
	}


	return 0;
}
