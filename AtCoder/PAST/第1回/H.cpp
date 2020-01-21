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


template<typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }
template<typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
	return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}
template<typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T& t, const V& v) { t = v; }
template<typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T& t, const V& v) {
	for (auto& e : t) fill_v(e, v);
}


// aよりもbが大きいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmax(T & a, const T & b) {
	if (a < b) {
		a = b;  // aをbで更新
		return true;
	}
	return false;
}
// aよりもbが小さいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmin(T & a, const T & b) {
	if (a > b) {
		a = b;  // aをbで更新
		return true;
	}
	return false;
}


#define ARRAY_MAX 100005
const int INF = 1e9 + 7;
const ll MOD = 1e9 + 7;

int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };


/******************************************************************************************/


ll A[200005];


int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);


	int n;
	cin >> n;
	vector<ll> C(n + 1);

	priority_queue<pll, vector<pll>, greater<pll> > od;
	priority_queue<pll, vector<pll>, greater<pll> > ev;

	for (int i = 1; i <= n; i++)
	{
		cin >> C[i];
		if (i % 2) {
			od.push(pll(C[i], i));
		}
		else
		{
			ev.push(pll(C[i], i));
		}
	}

	ll odd = 0;
	ll all = 0;

	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		char c;
		cin >> c;
		if (c == '1') {

			ll id, a;
			cin >> id >> a;

			if (C[id] - a >= A[id] + (id % 2) * odd + all) {
				A[id] += a;
				if (id % 2) {
					od.push(pll(C[id] - A[id] - odd - all, id));
				}
				else
				{
					ev.push(pll(C[id] - A[id] - all, id));
				}
			}

		}

		if (c == '2') {
			ll a;
			cin >> a;
			//奇数

			/*if (od.empty()) {
				continue;
			}*/
			pii mini = od.top();
			if (C[mini.second] - a >= A[mini.second] + odd + all) {
				odd += a;
				//od.pop();
				od.push(pll(C[mini.second] - A[mini.second] - odd - all, mini.second));
			}

		}

		if (c == '3') {
			ll a;
			cin >> a;

			pll miniOd, miniEv;

			miniOd = pll(INF, 0);
			miniEv = pll(INF, 0);

			/*if (od.empty() && ev.empty()) {
				continue;
			}*/

			if (!od.empty()) {
				miniOd = od.top();
			}
			if (!ev.empty()) {
				miniEv = ev.top();
			}

			if (miniOd.first >= miniEv.first) {

				//偶数の方
				if (C[miniEv.second] - a >= A[miniEv.second] + all) {
					//ev.pop();
					all += a;
					ev.push(pll(C[miniEv.second] - A[miniEv.second] - all, miniEv.second));
				}
			}
			else
			{
				if (C[miniOd.second] - a >= A[miniOd.second] + odd + all) {
					//od.pop();
					all += a;
					od.push(pll(C[miniOd.second] - A[miniOd.second] - odd - all, miniOd.second));
				}
			}
		}
	}

	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += A[i];
	}
	
	cout << ans + odd*((n+1)/2)  + all * n << endl;

	
	return 0;
}

