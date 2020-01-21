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
#include<cctype>

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

char ans[505][505];


int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);


	string s;
	cin >> s;
	vector<string> a;
	for (int i = 0; i < s.size(); i++)
	{

		if (isupper(s[i])) {
			int st = i;
			i++;
			while (i < s.size() && (!isupper(s[i]))) {
				i++;
			}

			a.push_back(s.substr(st, i - st + 1));
		}
	}



	for (int i = 0; i < a.size(); i++)
	{
		*a[i].begin() = tolower(*a[i].begin());
		a[i].back() = tolower(a[i].back());
	}

	sort(a.begin(), a.end());
	

	for (int i = 0; i < a.size(); i++)
	{
		cout << (char)toupper(*a[i].begin()) << a[i].substr(1, a[i].size() - 2) << (char)toupper(a[i].back());
	}

	return 0;
}
