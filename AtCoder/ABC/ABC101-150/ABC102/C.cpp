#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>

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
    vector<ll> a(n),b(n);
    REP(i,n){
        cin >> a[i];
        b[i]=a[i];
        a[i] -= (i+1);
    }
    VSORT(a);

    ll median = 0;
    ll sum = 0;

    median = a[a.size()/2];

    REP(i,n){
        sum+= abs(a[i]-median);
    }

    cout << sum << endl;

    return 0;
}
