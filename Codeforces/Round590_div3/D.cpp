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
#include<climits>
#include<bitset>

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
typedef tuple<ll, ll, ll, ll> lltpl;



/******************************************************************************************/


const int IINF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const ll MOD = 1e9 + 7;



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

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;
	int q;
	cin >> q;
	vector<set<int> > v(26);
	for (int i = 0; i < s.size(); i++)
	{
		v[s[i] - 'a'].insert(i);
	}

	for (int i = 0; i < q; i++)
	{
		
		int a;
		cin >> a;
		if (a == 1) {
			int b;
			char c;
			cin >> b >> c;
			b--;
			v[s[b] - 'a'].erase(b);
			s[b] = c;
			v[s[b] - 'a'].insert(b);
		}
		else
		{
			int l, r;
			cin >> l >> r;
			l--; r--;
			int cnt = 0;
			for (int j = 0; j < 26; j++)
			{
				auto it = v[j].lower_bound(l);
				if (it != v[j].end() && *it <= r) {
					cnt++;
				}
			}
			cout << cnt << endl;
		}
	}



}
 