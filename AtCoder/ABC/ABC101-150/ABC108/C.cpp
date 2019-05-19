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


    ll n,k;
    cin >> n >> k;

    ll ans = 0;

    if(k % 2 == 1){
        ll tmp = n/k;
        ans = tmp*tmp*tmp;
    }else{


        ll puni = n/(k/2);

        ll odd = puni/2;
        ll even = puni-odd;

        ans = odd*odd*odd + even*even*even;
    }
    
    cout << ans << endl;


    return 0;
}
