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
const int INF = INT32_MAX / 3;
const ll MOD = 1e9 + 7;

int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };


/******************************************************************************************/



//ユークリッド互除法
template<typename T>
T gcd(T x, T y) {

	if (y == 0) {
		return x;
	}
	else {
		return gcd(y, x % y);
	}
}

/*最小公倍数*/
template<typename T>
T lcm(T x, T y) {
	T tmp = gcd(x, y);

	return x * y / tmp;
}


int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);


    int n;
    cin >> n;
    vector<int> p(n),q(n),b(n);
    for (int i = 0; i < n; i++)
    {
        b[i]=i+1;
        cin >> p[i];
        /* code */
    }

     for (int i = 0; i < n; i++)
    {
        cin >> q[i];
        /* code */
    }
    
    int pa=0,qa=0;
    int cnt = 1;
    do
    {
        bool bp = true;
        for (int i = 0; i < n; i++)
        {
            /* code */
            bp &= (p[i]==b[i]);
        }
        
        if(bp){
            pa=cnt;
        }

         bool bq = true;
        for (int i = 0; i < n; i++)
        {
            /* code */
            bq &= (q[i]==b[i]);
        }
        
        if(bq){
            qa=cnt;
        }

        cnt++;
    } while (next_permutation(b.begin(),b.end()));
    


    cout << abs(qa-pa)<<endl;
	

	return 0;
}

