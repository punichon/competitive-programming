#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include<map>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 1e9
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;
typedef long long int ll;

int main(){

    ll n,t,a;
    cin >> n >> t >> a;

    double mini = 1e18;
    ll ans;
    REP(i,n){
        ll h;
        cin >> h;
        double tmp = t-0.006*h;
        if(abs(tmp-a) < mini){
            ans = i+1;
            mini = abs(tmp-a);
        }
    }
    cout << ans << endl;
  
    return 0;
}
