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

int dx2[2] = { 1,0 };
int dy2[2] = { 0,1 };

/******************************************************************************************/



int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);

	
	string s;
	cin >> s;

	deque<char> dq;

	for (int i = 0; i < s.size(); i++)
	{
		dq.push_back(s[i]);
	}


	int q;
	cin >> q;


	bool flag = true;

	//flagがtrue： 1で前，2で後ろ
	//flagがfalse： 1で後ろ，２で前

	for (int i = 0; i < q; i++)
	{
		int c;
		cin >> c;

		if (c == 1) {

			//反転
			flag = !flag;

		}
		else
		{
			int f;
			char p;
			cin >> f >> p;

			if (flag) {

				if (f == 1) {
					dq.push_front(p);
				}
				else
				{
					dq.push_back(p);
				}

			}
			else
			{
				if (f == 1) {
					dq.push_back(p);
				}
				else
				{
					dq.push_front(p);
				}
			}

		}


	}

	string ans;
	for (auto itr : dq) {
		ans.push_back(itr);
	}

	if (flag) {
		cout << ans << endl;
	}
	else
	{
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	}

	return 0;
}

