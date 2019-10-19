#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include<numeric>
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
#define ARRAY_MAX 100005
#define MOD 1000000007


int main(){

    ll R,C,K,N;
    cin >> R >> C >> K >> N;
    vector<ll> r(ARRAY_MAX),c(ARRAY_MAX);
    vector<ll> tate(ARRAY_MAX,0),yoko(ARRAY_MAX,0);//各行、列にある飴の個数
    vector<ll> tate_ame(ARRAY_MAX,0),yoko_ame(ARRAY_MAX,0);

    REP(i,N){
        cin >> r[i] >> c[i];
        r[i]--;
        c[i]--;
        tate[r[i]]++;
        yoko[c[i]]++;
    }
    REP(i,R){
        tate_ame[tate[i]]++;
    }
    
    REP(i,C){
        yoko_ame[yoko[i]]++;
    }
    
    ll ans = 0;
    for(ll i = 0;i <= K;i++){
        ans += tate_ame[i]*yoko_ame[K-i];
    }

    for(ll i = 0;i < N;i++){
        if(tate[r[i]] + yoko[c[i]] == K){
            ans--;
        }else if(tate[r[i]] + yoko[c[i]] == K+1){
            ans++;
        }
    }
    cout << ans << endl;




   
    return 0;
}
