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

struct hoge
{
	int index;
	string name;
	int num;

};

bool comp(const hoge& a, const hoge& b) {

	if (a.name == b.name) {
		return a.num > b.num;
	}
	else
	{
		return a.name < b.name;
	}

}

int main() {

	int n;
	cin >> n;
	vector<hoge> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].name >> a[i].num;
		a[i].index = i+1;

	}
	
	sort(a.begin(), a.end(), comp);

	for (int i = 0; i < n; i++)
	{
		cout << a[i].index << endl;
	}

	return 0;

}
