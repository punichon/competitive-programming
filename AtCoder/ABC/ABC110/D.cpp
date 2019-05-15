#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include <numeric>
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



/*素因数分解*/
map<ll,ll> prime_factorization(ll m){

    map<ll,ll> tmp;
    for(ll i = 2;i * i <= m;i++){
        while (m % i == 0) {
            tmp[i]++;
            m /= i;
        }
    }
    if(m != 1){
        tmp[m] = 1;
    }
    return tmp;
}

/*nCrの計算*/
ll nCr(ll n,ll r){

    if(n < r){
        return 0;
    }else if(n == r){
        return 1;
    }else{
        ll total = n,under1 = n-r,under2 = r;
        /*n!を求める*/
        for(ll i = n-1; i > 0;i--){
            total *= i;
            total %= MOD;
        }
        /*(n-r)!を求める*/
        for(ll i = n-r-1; i > 0;i--){
            under1 *= i;
            under1 %= MOD;
        }
        /*r!を求める*/
        for(ll i = r-1; i > 0;i--){
            under2 *= i;
            under2 %= MOD;
        }
        //cout << total << " " << under1 << " " << under2 << endl;
        /*(n-r)! * r!を求める*/
        ll under = (under1*under2) % MOD;
        return ((total % MOD) * calc(under,MOD-2,MOD)) % MOD;
    }
}





int main(){


    ll n,m;
    cin >> n >> m;
    map<ll,ll> prime_number = prime_factorization(m);

    map<ll,ll>::iterator ite;

    ll ans = 1;
    /*nHr = (n+r-1)Cr*/
    for(ite = prime_number.begin();ite != prime_number.end();ite++){
        ans *= nCr(n+ite->second-1,ite->second);
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
