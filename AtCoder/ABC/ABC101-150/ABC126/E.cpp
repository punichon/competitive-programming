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

/*
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
}*/


#define ARRAY_MAX 100005
const ll INF = 1e9 + 7;


int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };

const ll MOD = 1e9 + 7;



//繋げる方向を一方向にする
typedef struct union_find {

	vector<ll> pa;//親
	vector<ll> ra;//木の深さ
	vector<ll> siz;
	//n要素で初期化
	void init(ll n) {
		pa.resize(n);
		ra.resize(n);
		siz.resize(n);
		for (ll i = 0; i < n; i++) {
			pa[i] = i;/*各ノードに番号を振る,この時par[x]=xとなる時は木の根となる*/
			ra[i] = 0LL;/*各ノード自体の高さは0*/
			siz[i] = 1LL;
		}
	}
	//木の根を求める
	ll find(ll x) {
		if (pa[x] == x) {
			return x;/*根ならそのノードの番号を返す*/
		}
		else {
			return pa[x] = find(pa[x]);/*根でないならさらにノードの根を探す*/
		}
	}

	//xとyの属する集合を併合する
	void unite(ll x, ll y) {
		x = find(x);//xの根の番号を探す
		y = find(y);//yの根の番号を探す
		if (x == y) {//一致すればつながっている
			return;
		}
		pa[y] = x;
		siz[x] += siz[y];
	}

	//xとyが同じ集合に属するか判定
	bool same(ll x, ll y) {
		return find(x) == find(y);//同じ集合なら1、違うなら0が返る
	}
}UF;



int main() {

	int n, m;
	cin >> n >> m;
	UF tree;
	tree.init(n + 10);

	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		tree.unite(x, y);
	}

	set<int> st;
	for (int i = 1; i <= n; i++)
	{
		st.insert(tree.find(i));
	}
	cout << st.size() << endl;


	return 0;
}
