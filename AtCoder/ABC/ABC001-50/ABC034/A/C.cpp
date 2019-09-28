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
#define INF 999999999
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;
typedef long long int ll;

#define MOD 1000000007

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


int main(){

    ll h,w;
    cin >> h >> w;

    ll total = 1;
    ll under1 = 1;
    ll under2 = 1;

    for(int i = h+w-2 ; i > 0;i--){
        total *= i;
        total %= MOD;
    }
    for(int i = h-1; i > 0;i--){
        under1 *= i;
        under1 %= MOD;
    }

    for(int i = w-1; i > 0;i--){
        under2 *= i;
        under2 %= MOD;
    }
    
    ll under = (under1*under2) % MOD;
    //cout << under << endl;

   cout << ((total % MOD) * calc(under,MOD-2,MOD)) % MOD << endl;

    return 0;
}
