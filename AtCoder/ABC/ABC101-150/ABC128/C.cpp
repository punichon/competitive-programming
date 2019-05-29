#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<tuple>

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
typedef tuple<int, int, int> tiii;


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


#define ARRAY_MAX 100005
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };
const ll MOD = 1e9 + 7;
const ll INF = 1e9 + 7;


int main() {


	int n, m;
	cin >> n >> m;

	auto s = make_v<int>(m,0);
	vector<int> p(m);

	fill_v(s, 0);

	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			int tmp;
			cin >> tmp;
			s[i].push_back(tmp);
		}
	}

	for (int i = 0; i < m; i++)
	{
		cin >> p[i];
	}

	int ans = 0;
	for (int i = 0; i < (1 << n); i++)
	{
		bool ok = true;

		for (int j = 0; j < m; j++)
		{
			//m個の電球
			int cnt = 0;
			for (int k = 0; k < s[j].size(); k++)
			{
				//
				int tmp = s[j][k];
				tmp--;
				if ((i >> tmp) & 1) {
					//スイッチがオン
					cnt++;
				}
			}

			if ((cnt % 2) != p[j]) {
				//全部つかない
				ok = false;
				break;
			}
		}
		if (ok) {
			//cout << "i = " << i << endl;
			ans++;
		}
	}


	cout << ans << endl;



	return 0;

}
