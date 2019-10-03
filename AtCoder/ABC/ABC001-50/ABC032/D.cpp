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
#define ARRAY_MAX 1005
#define MAX_N 205

const ll INF = LLONG_MAX;

ll n,weight;
ll v[ARRAY_MAX],w[ARRAY_MAX];
ll dp[MAX_N][MAX_N*ARRAY_MAX+1];

ll solve1(){

    //dp[i][j]:=i番目までの品物までで重さwを作る時の最大価値
    memset(dp,0,sizeof(dp));
    for(int i = 0;i < n;i++){
        for(int j = 0;j <= weight;j++){
            if(j < w[i]){
                dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
            }else{
                dp[i+1][j] = max(dp[i][j],dp[i][j-w[i]] + v[i]);
            }
        }

    }
    return dp[n][weight];
}


ll solve2(){

    //dp[i][j]:=i番目までの品物まで見た時に、価値がjとなる時の最小の重さ
    for(int i = 0;i < MAX_N;i++){
        for(int j = 0;j <= MAX_N*ARRAY_MAX;j++){
            dp[i][j] = INF/3;
        }
    }
    //fill(dp[0],dp[0]+MAX_N*ARRAY_MAX+1,INF/3);
    dp[0][0] = 0;
    for(long i = 0;i < n;i++){
        for(long j = 0;j <= MAX_N*ARRAY_MAX;j++){
            if(j < v[i]){
                dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
            }else{
                dp[i+1][j] = min(dp[i][j],dp[i][j-v[i]] + w[i]);
            }
        }
    }
    ll ans = 0;
    for(ll i = 0;i <= MAX_N*ARRAY_MAX;i++){
        if(dp[n][i] <= weight){
            ans = i;
        }
    }
    return ans;
}


void build(ll bg, ll en, vector<pll> &t){

    ll m = en - bg;
    for(int i = 0;i < (1 << m);i++){
        ll vt = 0, wt = 0;
        for(int j = 0; j < m;j++){
            if((i >> j) & 1){
                vt += v[bg+j];
                wt += w[bg+j];
            }
        }
        if(wt > weight){
            continue;
        }
        t.push_back({wt,vt});
    }
    sort(t.begin(),t.end());
    ll vmax = 0;
    for(int i = 0;i < t.size();i++){
        vmax = max(vmax, t[i].second);
        t[i].second = vmax;
    }
}

int main(){

    cin >> n >> weight;
    ll maxi = -1;
    bool flag1 = false,flag2 = false;
    for(int i = 0;i < n;i++){
        cin >> v[i] >> w[i];
        maxi = max(maxi,w[i]);
    }

    if(n <= 30){
        //半分全列挙
        vector<pll> s1,s2;
        build(0,n/2,s1);
        build(n/2,n,s2);
        ll ans = 0;
        for(auto itr:s1){
            ll w1 = itr.first;
            ll v1 = itr.second;
            ll v2;
            v2 = (lower_bound(s2.begin(),s2.end(),pll(weight - w1,INF))-1)->second;
            ans = max(ans,v1+v2);
        }
        cout << ans << endl;
    }else if(maxi <= 1000){
        //価値dp
        cout << solve1() << endl;

    }else{
        //重さdp
        cout << solve2() << endl;
    }

    return 0;
}
