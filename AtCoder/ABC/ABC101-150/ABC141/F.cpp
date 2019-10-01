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

const int MAX_ROW = 70;
const int MAX_COL = 100005;
struct BitMatrix {
	int H, W;
	bitset<MAX_COL> val[MAX_ROW];
	BitMatrix(int m = 1, int n = 1) : H(m), W(n) {}
	inline bitset<MAX_COL>& operator [] (int i) { return val[i]; }
};

void GaussJordan(BitMatrix& A, bool is_extended = false) {
	vector<bool> used(A.H, 0);
	for (int col = 0; col < A.W; ++col) {
		if (is_extended && col == A.W - 1) break;
		int pivot = -1;
		for (int row = 0; row < A.H; ++row) {
			if (used[row]) continue;
			if (A[row][col]) {
				pivot = row;
				break;
			}
		}
		if (pivot == -1) continue;
		for (int row = 0; row < A.H; ++row) {
			if (row != pivot && A[row][col]) A[row] ^= A[pivot];
		}
		used[pivot] = true;
	}
}
const int MD = 62;

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);


	int N;
	cin >> N;
	vector<ll> A(N);
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	ll ans = 0;

	BitMatrix BM(MD+1, N+1);//65個の方程式，各方程式に対してN+1個の変数(0か1)
	//初期化時は，MD桁で， A_1+...+A_N=0ならば，列はN+1個で初期化すること（でないと落ちる）
	vector<bool> cannot(MD+1, 0);

	for (ll mask = MD; mask >= 0; mask--)
	{
		int num = 0;
		for (int i = 0; i < N; i++)
		{
			if ((A[i] >> mask) & 1LL) {
				num++;
			}
		}

		if (num == 0) {
			//全て0
			cannot[mask] = 1;
			continue;
		}
		else if (num & 1) {
			//1が奇数個(この桁は値は一定)
			cannot[mask] = 1;
			ans += (1LL << mask);
			continue;
		}

		//ここは1が偶数個存在する場合
		for (int i = 0; i < N; i++)
		{
			if ((A[i] >> mask) & 1LL) {
				BM[MD - mask][i] = 1;
			}

		}
		BM[MD - mask][N] = 1;
	}

	GaussJordan(BM, true);

	for (int mask = MD; mask >= 0; mask--)
	{
		if (cannot[mask]) {
			continue;
		}

		bool ok = false;

		for (int i = 0; i < N; i++)
		{
			if (BM[MD - mask][i]) {
				ok = true;
			}
		}
		if (!BM[MD - mask][N]) {
			ok = true;
		}

		if (ok) {
			ans += (1LL << (mask + 1));
		}
	}

	cout << ans << endl;
	

}

