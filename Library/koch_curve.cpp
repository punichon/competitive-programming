#include<algorithm>
#include<bitset>
#include<cassert>
#include<cfloat>
#include<climits>
#include<cmath>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>
#include<complex>
#include<list>

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




const ll INF = 1e18+7;

//verify:AOJ ALDS1_5_C 

/******************************************************************************************/

struct Point {
	double x;
	double y;
};


void koch(int n, Point p1, Point p2) {

	if (n == 0)return;

	Point s, t, u;

	double th = acos(-1) * 60.0 / 180.0;

	s.x = (2 * p1.x + p2.x) / 3;
	s.y = (2 * p1.y + p2.y) / 3;
	t.x = (p1.x + 2 * p2.x) / 3;
	t.y = (p1.y + 2 * p2.y) / 3;
	u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
	u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;

	koch(n - 1, p1, s);
	cout << s.x << " " << s.y << endl;
	koch(n - 1, s, u);
	cout << u.x << " " << u.y << endl;
	koch(n - 1, u, t);
	cout << t.x << " " << t.y << endl;
	koch(n - 1, t, p2);

}

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;

	Point p1, p2;
	p1.x = 0;
	p1.y = 0;
	p2.x = 100;
	p2.y = 0;

	cout << p1.x << " " << p1.y << endl;
	koch(n, p1, p2);
	cout << p2.x << " " << p2.y << endl;


	return 0;
}
