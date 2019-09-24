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
#include<climits>
#include<cstdio>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
using namespace std;
typedef pair<int, int> P;
typedef long long int ll;
typedef pair<ll,ll> LLP;
#define MOD 1000000007
#define ARRAY_MAX 1005
ll dx[4] = {1,0,0,-1};
ll dy[4] = {0,1,-1,0};
ll mp[ARRAY_MAX][ARRAY_MAX];
ll dp[ARRAY_MAX][ARRAY_MAX];
ll h,w;

bool Range(ll y,ll x){

    return (0 <= x && x < w && 0 <= y && y < h);
}

ll dfs(ll y,ll x){

    if(dp[y][x] != -1){
        return dp[y][x];
    }
    ll cnt = 1;
    REP(i,4){
        ll ny = y + dy[i];
        ll nx = x + dx[i];
        if(Range(ny,nx) && mp[y][x] < mp[ny][nx]){
            (cnt += dfs(ny,nx)) %= MOD;
        }
    }

    return ((dp[y][x] = cnt) % MOD);
}


int main(){

    cin >> h >> w;
    REP(i,h){
        REP(j,w){
            scanf("%lld",&mp[i][j]);
        }
    }

    memset(dp,-1,sizeof(dp));
    ll ans = 0;
    REP(i,h){
        REP(j,w){
            (ans += dfs(i,j)) %= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}
