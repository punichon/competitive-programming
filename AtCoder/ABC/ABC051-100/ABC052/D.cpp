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
typedef pair<ll,ll> pll;
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
#define MOD 1000000007
#define ARRAY_MAX 100005

const ll INF = 1LL << 60;

int main(){

    ll n,a,b;
    cin >> n >> a >> b;
    vector<ll> vec(n);
    for(int i = 0;i < n;i++){
        cin >> vec[i];
    }
    ll ans = 0;
    for(int i = 0;i < n-1;i++){
        ans += min((vec[i+1]-vec[i])*a,b);
    }
    cout << ans << endl;


    return 0;
}
