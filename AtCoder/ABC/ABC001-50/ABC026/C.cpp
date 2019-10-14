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

    ll n;
    cin >> n;
    vector<ll> a(n+2,0);
    vector<ll> money(n+1);

    ll maxi = -1;

    for(int i = 2;i < n+1;i++){
        cin >> a[i];
        //cout << a[i] << endl;
        maxi = max(maxi,a[i]);
    }

    
    for(int i = 2;i < n+1;i++){
        if(i > maxi){
            money[i] = 1;
        }
    }

    for(int i = maxi ; i>0 ; i--){
        ll maxi2 = -INF,mini = INF;
        for(int j = 2;j < n+1;j++){
            if(i == a[j]){
                maxi2 = max(maxi2,money[j]);
                mini = min(mini,money[j]);
            }
        }
        money[i] = maxi2 + mini + 1;
    }

    cout << money[1] << endl;

    return 0;
}
