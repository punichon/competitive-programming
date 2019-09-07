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
#include<queue>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 1000000007
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;
typedef long long int ll;
ll dx[4] = {1,0,0,-1};
ll dy[4] = {0,1,-1,0};

#define ARRAY_MAX 1005

int main(){

    ll n,t;
    cin >> n >> t;
    vector<ll> a(n),profit(n);
    ll mini = INF;
    ll maxi_profit = -1;

    REP(i,n){
        cin >> a[i];
        mini = min(mini,a[i]);
        profit[i] = a[i]-mini;
        maxi_profit = max(maxi_profit,profit[i]);
    }

    ll ans = 0;
    REP(i,n){
        if(profit[i] == maxi_profit){
            ans++;
        }
    }
    cout << ans << endl;


    return 0;
}
