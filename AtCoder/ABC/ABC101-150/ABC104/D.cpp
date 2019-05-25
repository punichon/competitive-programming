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

    ll n,m;
    cin >> n >> m;
    vector<ll> a(n);

    for(ll i = 0;i < n;i++){
        cin >> a[i];
    }

    map<ll,ll> mp;

    ll sum = 0,ans=0;
    mp[0]=1;

    for(ll i = 0;i < n;i++){

        sum += a[i];
        sum %= m;
        ans += mp[sum];
        mp[sum]++;

    }
    cout << ans << endl;


   
    return 0;
}
