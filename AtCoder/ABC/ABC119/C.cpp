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
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };
#define MOD 1000000007
#define ARRAY_MAX 100005

const int INF = 1e9 + 7;


int main() {

	int n, a, b, c;
	cin >> n >> a >> b >> c;
	vector<int> vec(n);

	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());

	int mini = INF;
	do {
		for (int i = 1; i <= n; i++) {//Aはi本
			for (int j = 1; j <= n; j++) {//Bはj本
				for (int k = 1; k <= n; k++) {//Cはk本使う
					if (i + j + k > n) {
						//使う竹がn本を超える場合は飛ばす
						continue;
					}
					int cost = 0;
					int cnt_a = 0, cnt_b = 0, cnt_c = 0;
					for (int x = 0; x < i; x++) {
						//竹を合わせた時の合計の長さ
						cnt_a += vec[x];
					}
					cost += (10 * (i - 1) + abs(a - cnt_a));//竹を合わせるコスト

					for (int y = i; y < i + j; y++) {
						cnt_b += vec[y];
					}
					cost += (10 * (j - 1) + abs(b - cnt_b));

					for (int z = i + j; z < i + j + k; z++) {
						cnt_c += vec[z];
					}
					cost += (10 * (k - 1) + abs(c - cnt_c));

					mini = min(mini, cost);
				}
			}
		}
	} while (next_permutation(vec.begin(), vec.end()));

	cout << mini << endl;

	return 0;
}
