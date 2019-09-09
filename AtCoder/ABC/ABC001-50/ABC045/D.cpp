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
#define INF 100005
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;
typedef long long int ll;

#define ARRAY_MAX 505

int main(){

    ll h,w,n;
    cin >> h >> w >> n;
    ll a,b;
    map<pair<ll,ll>,ll> mp;
    vector<ll> cnt(10,0);

    REP(i,n){
        cin >> a >> b;
        for(ll y = a;y <= a+2;y++){
            for(ll x = b;x <= b+2;x++){
                if(y-2 >= 1 && x-2 >= 1 && y <= h && x <= w){
                    mp[P(y,x)]++;
                }
            }
        }
    }

    ll sum = 0;
    for(auto itr:mp){
        cnt[itr.second]++;
    }

    for(int i = 1;i < 10;i++){
        sum += cnt[i];
    }

    cnt[0] = (h-2)*(w-2)-sum;

    REP(i,10){
        cout << cnt[i] << endl;
    }



    return 0;
}
