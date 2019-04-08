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
	for (int i = 0; i < 5; i++)
	{
		cin >> a[i];
	}

	int k;
	cin >> k;

	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			if (abs(a[j] - a[i] > k))
			{
				cout << ":(" << endl;
				return 0;
			}
		}
	}
	cout << "Yay!" << endl;




	return 0;
}
