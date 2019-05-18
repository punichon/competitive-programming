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

	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;


	vector<int> vec;

	if (s[0] == '0')
	{
		//番兵
		vec.push_back(0);
	}
	vec.push_back(0);
	vec.push_back(0);
	int cnt = 1;

	for (int i = 1; i < n; i++)
	{
		if (s[i] == s[i - 1])
		{
			cnt++;
		}
		else
		{
			vec.push_back(cnt);
			cnt = 1;
		}
	}
	vec.push_back(cnt);
	vec.push_back(0);

	int vec_siz = vec.size();

	for (int i = 0; i < vec_siz; i++) {
		if (i + 2 < vec_siz)
		{
			vec[i + 2] += vec[i];
		}
	}

	int maxi = 0;
	for (int i = 0; i < vec_siz - 1; i += 2)
	{
		//cout << i << endl;
		if (i + 2 * (k + 1) < vec_siz)
		{

			maxi = max(maxi, vec[i + 2 * (k + 1)] - vec[i] + vec[i + 2 * (k + 1) - 1] - vec[i + 1]);
		}
		else
		{
			maxi = max(maxi, vec[vec_siz - 1] - vec[i] + vec[vec_siz - 2] - vec[i + 1]);
		}
		//cout << "maxi = " << maxi << endl;
	}

	cout << maxi << endl;

}

