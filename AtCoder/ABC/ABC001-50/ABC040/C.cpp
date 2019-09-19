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

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    int dp[n+1];

    REP(i,n){
        cin >> a[i];
    }

    REP(i,n+1){
        dp[i] = 0;
    }


    dp[0] = 0;
    dp[1] = abs(a[1]-a[0]);
      
    for(int i = 2;i <= n;i++){

        dp[i] = min(dp[i-1]+abs(a[i]-a[i-1]), dp[i-2] + abs(a[i]-a[i-2]));
    
    }

    /*REP(i,n){
        cout << i << " " << dp[i] << endl;
    }*/

    cout << dp[n-1] << endl;
    
    return 0;
}
