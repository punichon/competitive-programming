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


using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
typedef pair<ll, ll> pll;
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };

#define ARRAY_MAX 100005

const ll INF = 1e9 + 7;
const ll MOD = 1e9 + 7;

int main() {

	string s;
	cin >> s;
	int maxi = 0;
	int cnt = 0;
	//cout << s << endl;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'A' || s[i] == 'T' || s[i] == 'G' || s[i] == 'C')
		{
			//cout << "a" << endl;
			cnt++;
		}
		else
		{
			//cout << "b" << endl;
			maxi = max(maxi, cnt);
			cnt = 0;
		}
	}

	maxi = max(maxi, cnt);
	cout << maxi << endl;


	return 0;
}
