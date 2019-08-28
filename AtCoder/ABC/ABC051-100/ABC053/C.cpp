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

#define ARRAY_MAX 505

int main(){

    ll n;
    cin >> n;
    ll ans = 2*(n/11);
    n%=11;
    //cout << ans << endl;
    //cout << n << endl;

    bool flag = true;
    while(n > 0){

        if(flag){
            n-=6;
            flag = !flag;
            ans++;
        }else{
            n-=5;
            flag = !flag;
            ans++;
        }
    }
    cout << ans << endl;


    return 0;
}
