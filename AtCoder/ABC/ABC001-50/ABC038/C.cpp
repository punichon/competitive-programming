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

ll dp[100001];

int main(){

    ll n;
    cin >> n;
    vector<ll> a(n);
    REP(i,n){
        cin >> a[i];
    }

    dp[0] = 1;

    ll first = 1;
    for(ll i = 1;i < n;i++){

        if(a[i] > a[i-1]){
            dp[i] = dp[i-1] + (i+1 - first + 1);
        }else{
            dp[i] = dp[i-1] + 1;
            first = i+1;
        }
    }
    cout << dp[n-1] << endl;

    return 0;
}
