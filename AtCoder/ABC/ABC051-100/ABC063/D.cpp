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




int main(){

    ll n,a,b;
    cin >> n >> a >> b;
    vector<ll> h(n);
    REP(i,n){
        cin >> h[i];
    }
    ll diff = a-b;
    ll lb = 0,ub = 1000000000;
    ll mid;

    while(ub - lb > 1){

        mid = (lb + ub)/2;
        ll cnt = 0;
        for(int i = 0;i < n;i++){

            if(h[i] > b * mid){
                cnt += (h[i]-b*mid-1)/diff + 1;
            }
        }

        if(cnt > mid){
            /*mid回以上かかる*/
            lb = mid;
        }else{
            /*mid回以内で終わる*/
            ub = mid;
        }
    }
    cout << ub << endl;



    return 0;
}
