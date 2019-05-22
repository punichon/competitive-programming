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

	string s;
	cin >> s;

	bool yymm = true;
	bool mmyy = true;

	int num = 0;

	for (int i = 0; i < 2; i++)
	{
		num = num * 10 + s[i] - '0';
	}

	int left = num;

	num = 0;
	for (int i = 2; i < s.size(); i++)
	{
		num = num * 10 + s[i] - '0';
	}

	int right = num;

	if (1 <= right && right <= 12 && 1 <= left && left <= 12)
	{
		cout << "AMBIGUOUS" << endl;
	}
	else
	{
		if (1 <= right && right <= 12)
		{
			cout << "YYMM" << endl;

		}
		else if (1 <= left && left <= 12)
		{
			cout << "MMYY" << endl;
		}
		else
		{
			cout << "NA" << endl;
		}
	}
	

	return 0;
}

