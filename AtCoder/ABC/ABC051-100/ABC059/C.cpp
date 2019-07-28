#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include<set>

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
    REP(i,n){
        cin >> a[i];
    }

    ll sum = 0;
    ll ans1 = 0;

    /*正負の順*/
    for(int i = 0,s = 1; i < n; i++,s*= -1){
        sum += a[i];
        if(sum * s <= 0){
            ans1+= abs(sum-s);
            sum = s;
        }
    }
    sum = 0;
    /*負正の順*/
    ll ans2 = 0;
    for(int i = 0,s = -1; i < n; i++,s*= -1){
        sum += a[i];
        if(sum * s <= 0){
            ans2+= abs(sum-s);
            sum = s;
        }
    }
    cout << min(ans1,ans2) << endl;




   
    return 0;
}
