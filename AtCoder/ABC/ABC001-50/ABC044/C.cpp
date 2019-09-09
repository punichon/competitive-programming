#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 999999999
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;
typedef long long int ll;

#define N_MAX 51
#define X_MAX 51

ll dp[51][51][2501];

int main(){

    ll n,a;
    cin >> n >> a;
    vector<ll> ary(n);
    REP(i,n){
        cin >> ary[i];
    }
    dp[0][0][0] = 1;

    for(ll i = 1;i <= n;i++){

        for(ll j = 0;j <= n;j++){

            for(ll k = 0;k <= 2500;k++){

                if(i >= 1 && ary[i-1] > k){
                    dp[i][j][k] = dp[i-1][j][k];
                }else if(i >= 1 && j >= 1 && ary[i-1] <= k){
                    dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k-ary[i-1]];
                }else{
                    dp[i][j][k] = 0;
                }
            }
        }
    }


    ll ans = 0;
    for(ll i = 1;i <= n;i++){
        ans += dp[n][i][i*a];
    }
    cout << ans << endl;

   
    return 0;
}
