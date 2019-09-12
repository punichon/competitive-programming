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

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 1000000000
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;
typedef long long int ll;

#define ARRAY_MAX 100005
#define MOD 1000000007

ll factorial[2*ARRAY_MAX];
ll inverse[2*ARRAY_MAX];

/*mod Mでの割り算は割る数aのM-2をかける*/
/*ここではaのb乗をpで割った余りを返す*/
ll calc(ll a,ll b,ll p){

   if(b == 0){
       return 1;
   }else if(b % 2 == 0){
       ll tmp = (calc(a,b/2,p)) % p;
       return ((tmp%p)*(tmp%p))%p;
   }else{
       return ((a%p)*(calc(a,b-1,p)%p)) % p;
   }
}

ll calc_nCr(ll n,ll r){

    return ((factorial[n]*inverse[r])%MOD*inverse[n-r])%MOD;
}

int main(){

    ll h,w,a,b;
    cin >> h >> w >> a >> b;
    factorial[0] = factorial[1] = 1;
    for(ll i = 2;i <= h+w-2;i++){
        factorial[i] = factorial[i-1] * i % MOD;
    }
    for(ll i = 0;i <= h+w-2;i++){
        inverse[i] = calc(factorial[i],MOD-2,MOD);
    }

    ll n = h-a-1;
    ll down = a-1;
    ll ans = 0;

    for(ll i = b;i < w;i++){
        
        ll right = w-i-1;
        //cout << right << endl;
        ans = (ans + (calc_nCr(n+i,i) * calc_nCr(down+right,right))%MOD)%MOD;
    }
    cout << ans << endl;

    




    return 0;
}
