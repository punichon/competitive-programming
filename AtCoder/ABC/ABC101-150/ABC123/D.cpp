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

	ll a, b, c, k;
	cin >> a >> b >> c >> k;
	vector<ll> x(a), y(b), z(c);
	for (int i = 0; i < a; i++)
	{
		cin >> x[i];
	}

	for (int i = 0; i < b; i++)
	{
		cin >> y[i];
	}

	for (int i = 0; i < c; i++)
	{
		cin >> z[i];
	}

	vector<ll> vec;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			vec.push_back(x[i] + y[j]);
		}
	}

	sort(vec.rbegin(), vec.rend());

	ll siz = vec.size();

	vector<ll> ans;

	for (int i = 0; i < min(siz, k); i++)
	{
		//ã‚©‚çkŒÂ‚Æ‘g‚Ý‡‚í‚¹‚é
		for (int j = 0; j < c; j++)
		{
			ans.push_back(vec[i] + z[j]);
		}
	}

	sort(ans.rbegin(), ans.rend());
	siz = ans.size();
	for (int i = 0; i < min(k, siz); i++)
	{
		cout << ans[i] << endl;
	}

	return 0;
}
