#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include<cstdio>
#include<map>
#include<set>
#include<queue>

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



/*素因数分解*/
map<ll,ll> prime_factorization(ll m){

    map<ll,ll> tmp;
    for(ll i = 2;i * i <= m;i++){
        while(m % i == 0) {
            tmp[i]++;
            m /= i;
        }
    }
    if(m != 1){
        tmp[m] = 1;
    }
    return tmp;
}


int main(){

    ll n;
    cin >> n;
    map<ll,ll> mp;

    map<ll,ll>::iterator itr;
    for(int i = 1;i <= n;i++){
        //n!の素因数分解
        map<ll,ll> tmp = prime_factorization(i);
        for(itr = tmp.begin();itr != tmp.end();itr++){
            mp[itr->first] += itr->second;
        }
    }
    mp[1] = 1;

    ll ans = 0;
    //75乗のやつ
    for(itr=mp.begin();itr != mp.end();itr++){
        if(itr->second >= 74){
            ans++;
        }
    }

    map<ll,ll> a,b,c;//25×3用と5×5×3用と15×3用
    //25乗×3乗
    for(itr=mp.begin();itr != mp.end();itr++){
        if(itr->second >= 24){
            a[24]++;
        }
        if(itr->second >= 2){
            a[2]++;
            b[2]++;
        }
        if(itr->second >= 4){
            b[4]++;
        }
        if(itr->second >= 14){
            c[14]++;
        }
        if(itr->second >= 4){
            c[4]++;
        }
    }
    //25乗×3乗
   
    ans += a[24]*(a[2]-1);
    ans += b[4]*(b[4]-1)*(b[2]-2)/2;
    ans += c[14]*(c[4]-1);
    
    cout << ans << endl;



    return 0;
}
