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


#define ARRAY_MAX 100005
const ll INF = 1e9 + 7;




/*素数のみの配列を返す*/
vector<ll> Eratosthenes(ll n, vector<ll>& arr) {

	for (ll i = 0; i <= n; i++) {
		arr[i] = 1;
	}

	for (ll i = 2; i <= sqrt(n); i++) {
		if (arr[i]) {
			for (ll j = 0; i * (j + 2) < n; j++) {
				arr[i *(j + 2)] = 0;
			}
		}
	}
	vector<ll> prime;
	for (int i = 2; i < arr.size(); i++) {
		if (arr[i]) {
			prime.push_back(i);
		}
	}
	return prime;
}



int main() {


	ll n;
	cin >> n;
	vector<ll> vec(60000, 1);
	vector<ll> num = Eratosthenes(55555, vec);


	ll cnt = 0;
	vector<ll> ans;
	for (int i = 0; i < num.size(); i++)
	{
		if ((num[i] % 5) == 1)
		{
			ans.push_back(num[i]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			cout << ans[i];
		}
		else
		{
			cout << " " << ans[i];
		}
	}
	cout << endl;


	return 0;
}



