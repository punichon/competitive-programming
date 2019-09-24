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


    int n,k;
    cin >> n >> k;
    vector<ll> a(100005);
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    a[0] = 0;

    for(int i = 1;i <=n;i++){
        a[i+1] += a[i];
    }
    /*REP(i,n+1){
        cout << a[i] << endl;
    }*/
    ll ans = 0;


    for(int i = k;i <= n;i++){

        ans += a[i] - a[i-k];
        //cout << ans << endl;

    }
    cout << ans << endl;
    return 0;
}
