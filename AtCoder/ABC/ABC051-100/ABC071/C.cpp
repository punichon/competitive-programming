#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 1000000000
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;
typedef long long int ll;

#define ARRAY_MAX 100005


int main(){

    ll n,ans = 0;
    cin >> n;
    vector<ll> a(n);
    map<ll,ll> mp;

    REP(i,n){
        cin >> a[i];
        mp[a[i]]++;
    }
    ll cnt = 0;//辺の数2以上である長さを持つ辺の個の個数
    for(auto itr:mp){
        if(itr.second >= 2){
            cnt++;
        }
    }
    ll maxi = -INF,sec_maxi = -INF;
    ll tmp = maxi*sec_maxi;
    ans = tmp;
    ll maxi_edge_num = 0;
    for(auto itr:mp){
        if(itr.second >= 2){
            maxi = max(maxi,itr.first);
            maxi_edge_num = itr.second;
        }
    }
    if(maxi_edge_num >= 4){
        ans = maxi*maxi;
    }else{
        for(auto itr:mp){
            if(itr.second >= 2 && itr.first < maxi){
                sec_maxi = max(sec_maxi,itr.first);
            }
        }
        ans = maxi * sec_maxi;
    }
    if(ans == tmp){
        ans = 0;
    }
    cout << ans << endl;

   

    return 0;
}
