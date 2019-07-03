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

int main() {

	int n, k;
	cin >> n >> k;

	int ans;
	ans = 1;//現在の値

	for (int i = 1; i <= n; i++)
	{
		//i回目の処理
		int A, B;
		A = 2 * ans;
		B = ans + k;
		if (A < B)
		{
			ans = A;
		}
		else {
			ans = B;
		}
	}

	cout << ans << endl;
	


	return 0;
}
