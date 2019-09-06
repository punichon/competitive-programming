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


    ll n,x;
    cin >> n >> x;
    vector<ll> a(ARRAY_MAX,0);
    REP(i,n){
        cin >> a[i];
    }

    ll ans = 0;
    ll tmp = 0;
    REP(i,n){
        
        if(tmp + a[i] > x){
            //cout << i << " a " << tmp+a[i]-x << endl;
            ans += tmp+a[i]-x;
            a[i] = a[i] - (tmp+a[i]-x);
            tmp = a[i];
            if(a[i] > x){
                ans += a[i]-x;
                a[i] = x;
                tmp = a[i];
            }
        }else if(a[i] > x){
            ans += a[i]-x;
            a[i] = x;
            tmp = a[i];
        }else{
            tmp = a[i];
        }

    }
    cout << ans << endl;


    return 0;
}
