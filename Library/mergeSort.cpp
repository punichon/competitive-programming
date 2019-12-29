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

int L[500005];
int R[500005];
int cnt = 0;

void merge(vector<int>& a, int n, int left, int mid, int right) {

	int n1 = mid - left;
	int n2 = right - mid;
	for (int i = 0; i < n1; i++)
	{
		L[i] = a[left + i];
	}
	for (int i = 0; i < n2; i++)
	{
		R[i] = a[mid + i];
	}
	L[n1] = R[n2] = INF;

	int i = 0, j = 0;
	for (int k = left; k < right; k++)
	{
		cnt++;
		if (L[i] <= R[j]) {
			a[k] = L[i++];
		}
		else
		{
			a[k] = R[j++];
		}
	}
}



void mergeSort(vector<int>& a, int n, int left, int right) {

	if (left + 1 < right) {

		int mid = (right + left) / 2;
		mergeSort(a, n, left, mid);
		mergeSort(a, n, mid, right);
		merge(a, n, left, mid, right);

	}

}


//verify:AOJ ALDS1_5_B 

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	mergeSort(a, n, 0, n);

	for (int i = 0; i < n; i++)
	{
		if (i)cout << " ";
		cout << a[i];
	}
	cout << endl;
	

	cout << cnt << endl;

	return 0;
}
