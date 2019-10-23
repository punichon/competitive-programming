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
#include<stack>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define repi(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> lltpl;

int dy8[8] = { 2,2,-2,-2,1,1,-1,-1 };
int dx8[8] = { 1,-1,1,-1,2,-2,2,-2 };
int dx4[4] = { 1,0,0,-1 };
int dy4[4] = { 0,1,-1,0 };


/******************************************************************************************/


const int IINF = 1e9 + 7;
const ll LINF = 1e17 + 7;
constexpr ll MOD = 1e9 + 7;



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

// vector
template <typename T>
istream& operator>>(istream & is, vector<T> & vec) { for (T& x : vec) is >> x; return is; }
// pair
template <typename T, typename U>ostream& operator<<(ostream & os, pair<T, U> & pair_var) { os << "(" << pair_var.first << ", " << pair_var.second << ")"; return os; }
// vector
template <typename T>ostream& operator<<(ostream & os, const vector<T> & vec) { os << "{";	for (int i = 0; i < vec.size(); i++) { os << vec[i] << (i + 1 == vec.size() ? "" : ", "); }os << "}"; return os; }
// map
template <typename T, typename U>ostream& operator<<(ostream & os, map<T, U> & map_var) { os << "{";	repi(itr, map_var) { os << *itr; itr++; if (itr != map_var.end()) os << ", "; itr--; }os << "}"; return os; }
// set
template <typename T>ostream& operator<<(ostream & os, set<T> & set_var) { os << "{"; repi(itr, set_var) { os << *itr; itr++; if (itr != set_var.end()) os << ", "; itr--; }os << "}"; return os; }


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

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int Q, N;
	cin >> Q;
	for (int _ = 0; _ < Q; _++)
	{
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; i++)
		{
			cin >> A[i];
			A[i]--;
		}

		UF tree;
		tree.init((ll)N + 10);

		
		for (int i = 0; i < N; i++)
		{
			if (i > A[i]) {
				tree.unite(A[i], i);
			}
			else
			{
				tree.unite(i, A[i]);
			}
			
		}

		for (int i = 0; i < N; i++)
		{
			if (i == 0) {
				printf("%lld", tree.siz[tree.find(i)]);
			}
			else
			{
				printf(" %lld", tree.siz[tree.find(i)]);
			}
		}
		putchar('\n');
	}
	return 0;
}