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

	int n, q;
	string s;
	cin >> n >> q;
	cin >> s;
	vector<int> cnt(n + 10, 0);

	int cnt_a = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'C' && cnt_a == 1)
		{
			cnt[i + 1]++;
			cnt_a--;
		}
		else if (s[i] == 'A')
		{
			if (cnt_a == 0)
			{
				cnt_a = 1;
			}
		}
		else if (s[i] != 'A' && cnt_a == 1)
		{
			cnt_a = 0;
		}
	}

	
	for (int i = 0; i < s.length(); i++)
	{
		cnt[i + 1] += cnt[i];
	}

	for (int i = 0; i < q; i++)
	{
		int l, r;
		cin >> l >> r;
		cout << cnt[r] - cnt[l] << endl;
	}
	return 0;
}
