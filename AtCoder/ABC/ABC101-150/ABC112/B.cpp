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
#define INF 1e9
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;

int main(){

    int n,t,ans = INF;
    cin >> n >> t;
    vector<int> co(n),ti(n);
    REP(i,n){
        cin >> co[i] >> ti[i];
    }

    for(int i = 0;i < n;i++){
        if(ti[i] <= t){
            ans = min(ans,co[i]);
        }
    }
    if(ans == INF){
        cout << "TLE" << endl;
    }else{
        cout << ans << endl;
    }
  
    return 0;
}
