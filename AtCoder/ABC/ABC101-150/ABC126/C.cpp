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
typedef pair<int, int> pii;

typedef long long int ll;

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


#define ARRAY_MAX 5005
const ll INF = 1e9 + 7;


int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };




int main() {

	ll n, k;
	cin >> n >> k;
	double ans = 0;


	int hoge = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i >= k)
		{
			hoge++;
		}
		else
		{
			int cnt = ceil(log2(k / (double)i));
			ans += 1 / (n*pow(2LL, cnt));
			//cout << "cnt= " << cnt << endl;
		}
		
		//cout << ans << endl;
		//cout << "cnt= " << cnt << endl;
	}

	ans += hoge / double(n);
	printf("%.12f\n", ans);

	return 0;
}

