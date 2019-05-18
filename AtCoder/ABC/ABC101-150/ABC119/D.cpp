#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#include<climits>
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
typedef pair<ll, ll> pll;
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };
#define MOD 1000000007
#define ARRAY_MAX 100005

const ll INF = 1e17 + 7;


int main() {

	ll a, b, q;
	cin >> a >> b >> q;
	vector<ll> s(a), t(b);
	for (int i = 0; i < a; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < b; i++) {
		cin >> t[i];
	}

	for (int i = 0; i < q; i++) {
		ll query;
		cin >> query;
		auto s_i = lower_bound(s.begin(), s.end(), query);
		auto t_i = lower_bound(t.begin(), t.end(), query);
		if (s_i == s.end()) {
			s_i--;
		}
		if (t_i == t.end()) {
			t_i--;
		}
		vector<ll> ta, tb;
		ta.push_back(*s_i);
		if (s_i != s.begin()) {
			s_i--;
			ta.push_back(*s_i);
		}
		tb.push_back(*t_i);

		if (t_i != t.begin()) {
			t_i--;
			tb.push_back(*t_i);
		}

	
		ll mini = INF;

		//AÅ®B
		ll now = query;
		for (int i = 0; i < ta.size(); i++) {
			for (int j = 0; j < tb.size(); j++) {
				ll tmp = 0;
				ll now = query;
				tmp += (ll)abs(ta[i] - now);//Ç‹Ç∏AÇ…çsÇ≠
				now = ta[i];
				tmp += (ll)abs(tb[j] - now);
				mini = min(mini, tmp);
			}
		}
		//cout << mini << endl;
		//BÅ®A
		for (int i = 0; i < tb.size(); i++) {
			for (int j = 0; j < ta.size(); j++) {
				ll tmp = 0;
				ll now = query;
				tmp += (ll)abs(tb[i] - now);//Ç‹Ç∏bÇ…çsÇ≠
				now = tb[i];
				tmp += (ll)abs(ta[j] - now);
				mini = min(mini, tmp);
			}
		}
		cout << mini << endl;
	}







	return 0;
}
