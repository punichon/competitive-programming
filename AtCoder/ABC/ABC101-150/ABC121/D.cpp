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
//int dx[4] = { 1,0,0,-1 };
//int dy[4] = { 0,1,-1,0 };
#define MOD 1000000007
#define ARRAY_MAX 55

const int INF = 1e9 + 7;


int main() {


	ios::sync_with_stdio(false);
	cin.tie(0);

	ll a, b;
	cin >> a >> b;

	ll ans = 0;

	//bit最大は45くらいで
	vector<ll> bit(ARRAY_MAX, 0);

	if ((((b + 1) / 2) % 2) == 1) {
		bit[0] ^= 1;
	}

	//bの各桁のビットを求める
	for (ll i = 45; i > 0; i--) {
		//1桁目は別で調べる
		//i桁目を見る
		ll high = 1LL << (i + 1);//これで割る
		ll low = 1LL << i;
		if (b%high >= low) {
			if ((b%high) % 2 == 0) {
				//この数字まで1が奇数個ある
				bit[i] ^= 1LL;
			}
		}
	}

	a--;//累積和の感覚

	//1桁目
	if ((((a + 1) / 2) % 2) == 1) {
		bit[0] ^= 1LL;
	}

	for (ll i = 45; i > 0; i--) {
		//1桁目は別で調べる
		//i桁目を見る
		ll high = 1LL << (i + 1);//これで割る
		ll low = 1LL << i;
		if (a%high >= low) {
			if ((a%high) % 2 == 0) {
				//この数字まで1が奇数個ある
				bit[i] ^= 1LL;
			}
		}
	}

	for (int i = 0; i <= 45; i++) {
		if (bit[i] == 1) {
			ans += (1LL << i);
		}
	}
	cout << ans << endl;

	return 0;
}
