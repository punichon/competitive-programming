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

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 1000000000
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;
typedef long long int ll;

#define ARRAY_MAX 105

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

	string s;
	cin >> s;
	int siz = s.size();
	string t, k;
	for (int i = 0; i < siz; i++)
	{
		if ((i % 2) == 0)
		{
			t.push_back('0');
		}
		else
		{
			t.push_back('1');
		}
	}

	for (int i = 0; i < siz; i++)
	{
		if ((i % 2) == 0)
		{
			k.push_back('1');
		}
		else
		{
			k.push_back('0');
		}
	}

	int ans = INF;
	int cnt = 0;
	for (int i = 0; i < siz; i++)
	{
		if (s[i] != t[i])
		{
			cnt++;
		}
	}

	ans = min(ans,cnt);
	cnt = 0;

	for (int i = 0; i < siz; i++)
	{
		if (s[i] != k[i])
		{
			cnt++;
		}
	}
	ans = min(ans, cnt);

	cout << ans << endl;

}
