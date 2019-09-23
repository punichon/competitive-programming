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

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;


//BinaryIndexTree(siz):長さsizで初期化


template<typename T>
struct BinaryIndexTree {

	vector<T> data;

	BinaryIndexTree(int siz)
	{
		//1-indexなので配列は1つ多めに用意する
		data.resize(siz + 1, 0);
	}
	T getMax(int k)
	{
		//a_1～a_kまでの最大値
		T ret = 0;
		for (int i = k; i > 0; i -= (i & -i))
		{
			if (ret < data[i])
			{
				ret = data[i];
			}
		}
		return ret;
	}

	void update(int k, int x)
	{
		//最大値の更新
		for (int i = k; i < data.size(); i += (i & -i))
		{
			if (data[i] < x)
			{
				data[i] = x;
			}
		}
	}
};

bool comp(pii& a, pii& b) {

	if (a.first == b.first)
	{
		//wが同じならhは降順
		return a.second > b.second;
	}
	else
	{
		return a.first < b.first;
	}
}

int dp[ARRAY_MAX];

int main() {

	ll n;
	cin >> n;

	vector<pii> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}

	BinaryIndexTree<int> tree(ARRAY_MAX);
	sort(a.begin(), a.end(),comp);

	for (int i = 0; i < n; i++)
	{
		int h = a[i].second;
		dp[i] = tree.getMax(h-1) + 1;
		tree.update(h, dp[i]);
	}

	int maxi = 0;

	for (int i = 0; i < n; i++)
	{
		maxi = max(maxi, dp[i]);
	}
	cout << maxi << endl;


	return 0;
}
