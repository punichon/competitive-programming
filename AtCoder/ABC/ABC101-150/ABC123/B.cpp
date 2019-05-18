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

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int main() {

	vector<int> a(5);
	int mini = INF;

	for (int i = 0; i < 5; i++)
	{
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	do {
		int tm = 0;
		for (int i = 0; i < 5; i++)
		{
			if (tm % 10 == 0)
			{
				tm += a[i];
			}
			else
			{
				while (tm % 10 != 0)
				{
					tm++;
				}
				tm += a[i];
			}
		}
		mini = min(mini, tm);
	} while (next_permutation(a.begin(), a.end()));

	cout << mini << endl;

	return 0;
}
