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

	string s, t;
	cin >> s >> t;
	int s_len = s.length();
	int t_len = t.length();
	bool ans = false;
	int maxi = -1;

	for (int i = 0; i <= s_len-t_len; i++)
	{
		bool exist = true;
		string tmp = s.substr(i, t_len);//部分文字列
		for (int j = 0; j < t_len; j++) {
			if (tmp[j] != t[j])
			{
				if (tmp[j] != '?')
				{
					exist = false;
					break;
				}
			}
		}
		if (exist)
		{
			maxi = max(maxi, i);
		}
	}

	if (maxi == -1)
	{
		cout << "UNRESTORABLE" << endl;
	}
	else
	{
		for (int i = maxi; i < maxi + t_len; i++) {
			s[i] = t[i - maxi];
		}
		for (int i = 0; i < s_len; i++)
		{
			if (s[i] == '?')
			{
				s[i] = 'a';
			}
		}
		cout << s << endl;
	}


	return 0;
}
