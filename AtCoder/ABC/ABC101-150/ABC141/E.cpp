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


const ll INF = 1e9 + 7;
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

struct Z_algorithm
{
	vector< int > prefix;

	void build(const string& s)
	{
		prefix.assign(s.size(), 0);
		for (int i = 1, j = 0; i < s.size(); i++) {
			if (i + prefix[i - j] < j + prefix[j]) {
				prefix[i] = prefix[i - j];
			}
			else {
				int k = max(0, j + prefix[j] - i);
				while (i + k < s.size() && s[k] == s[i + k]) ++k;
				prefix[i] = k;
				j = i;
			}
		}
		prefix[0] = (int)s.size();
	}

	int operator[](const int k) const
	{
		return (prefix[k]);
	}

	size_t size()
	{
		return(prefix.size());
	}
};


int main() {
	
	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		string T = s.substr(i);

		Z_algorithm tapi;
		tapi.build(T);

		for (int j = 0; j < T.size(); j++)
		{
			ans = max(ans, min(tapi.prefix[j],j));
		}

	}

	cout << ans << endl;



}
