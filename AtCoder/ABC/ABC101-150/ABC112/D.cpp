#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cstring>
#include<cmath>
#include <numeric>
#include<queue>
#include<climits>
#include<cstdio>
#include<map>


#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
//#define INF ((LLONG_MAX) / (2))
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;
typedef long long int ll;
typedef pair<ll,int> LL_IP;
#define INF 1e9+7
#define N_MAX 1001


/*約数列挙*/
vector<ll> prime_factorization(ll m){
    
    vector<ll> arr;
    for(ll i = 1;i * i <= m;i++){
        if(m % i == 0){
            arr.push_back(i);
            if(i != m/i){
                arr.push_back(m/i);
            }
        }
    }
    return arr;
}

int main(){

    ll n,m,ans = -1;
    cin >> n >> m;
    vector<ll> arr = prime_factorization(m);

    REP(i,arr.size()){
        if(n * arr[i] <= m){
            ans = max(arr[i],ans);
        }
    }
    cout << ans << endl;



    return 0;
}
