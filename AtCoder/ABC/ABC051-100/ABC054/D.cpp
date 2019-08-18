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
using namespace std;

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define VSORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)


typedef long long ll;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1e9 + 7;

#define ARRAY_MAX 100005

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


int n, ma, mb;

struct goods {

	int a;
	int b;
	int c;

};


void build(int bg, int en, vector<goods>& t, map<pii,int>& ans) {

	int m = en - bg;
	for (int i = 0; i < (1 << m); i++) {
		int aa = 0, bb = 0, cc = 0;

		for (int j = 0; j < m; j++) {
			if ((i >> j) & 1) {
				aa += t[bg + j].a;
				bb += t[bg + j].b;
				cc += t[bg + j].c;
			}
		}
		if (ans.count({ aa,bb }) == 0 || ans[{aa,bb}] > cc)
		{
			ans[{aa, bb}] = cc;
		}
	}
}

int main() {

	
	cin >> n >> ma >> mb;


	vector<goods> vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i].a >> vec[i].b >> vec[i].c;
	}

	map<pii,int> ans1, ans2;

	build(0, n / 2, vec, ans1);
	build(n / 2, n, vec, ans2);

	int mini = INF;

	for (auto itr: ans1)
	{
		for (auto itr2 : ans2)
		{
			int aa = itr.first.first + itr2.first.first;
			int bb = itr.first.second + itr2.first.second;
			
			if (aa * mb == bb * ma && itr.second + itr2.second != 0)
			{
				mini = min(mini, itr.second + itr2.second);
			}
		}
	}
	if (mini == INF)
	{
		cout << "-1" << endl;
	}
	else
	{
		cout << mini << endl;
	}

	return 0;
}
