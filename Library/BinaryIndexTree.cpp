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
#define MOD 1000000007
#define ARRAY_MAX 100005

const double INF = 1e15 + 7;

//BinaryIndexTree(siz):長さsizで初期化
//sum(k):区間[0,k]の和を求める
//add(k,x):要素kにxを加える

template<typename T>
struct BinaryIndexTree {

	vector<T> data;
	
	BinaryIndexTree(int siz)
	{
		//1-indexなので配列は1つ多めに用意する
		data.resize(siz + 1, 0);
	}
	T sum(int k) 
	{
		//a_1～a_kまでの和を計算
		T ret = 0;
		for (int i = k; i > 0; i -= (i & -i))
		{
			ret += data[i];
		}
		return ret;
	}

	void add(int k, int x)
	{
		//a_kにxを加算する
		for (int i = k; i < data.size(); i += (i& -i))
		{
			data[i] += x;
		}
	}
};



int main() {


	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, q;
	cin >> n >> q;

	BinaryIndexTree<int> bit(n);

	for (int i = 0; i < q; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0)
		{
			bit.add(b , c);
		}
		else
		{
			cout << bit.sum(c) - bit.sum(b - 1) << endl;
		}
	}

	return 0;
}