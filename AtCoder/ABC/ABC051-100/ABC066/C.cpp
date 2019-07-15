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


int main() {

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	deque<int> que;

	if (n % 2)
	{
		for (int i = 0; i < n; i++)
		{
			if (i % 2)
			{
				que.push_back(a[i]);
			}
			else
			{
				que.push_front(a[i]);
			}
		}


	}
	else
	{

		for (int i = 0; i < n; i++)
		{
			if (i % 2)
			{
				que.push_front(a[i]);
			}
			else
			{
				que.push_back(a[i]);
			}
		}
		
	}
	int cnt = 0;
	for (auto itr : que)
	{
		if (cnt == 0)
		{
			cout << itr;
		}
		else 
		{
			cout << " " << itr;
		}
		cnt++;
	}
	cout << endl;
	
	return 0;
}
