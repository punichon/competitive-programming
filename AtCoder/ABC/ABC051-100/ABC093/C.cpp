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
#define INF 1000000007
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;
typedef pair<ll,int> LL_IP;


int main(){

    ll a,b,c,ans = 0;
    cin >> a >> b >> c;
    ll maxi = max(a,max(b,c));
    ll mini = min(a,min(b,c));
    ll middle = a+b+c-maxi-mini;
  
    if(middle % 2 == mini % 2){
        ans += (middle-mini)/2;
        ans += (maxi-middle);
    }else{

        while(middle % 2 != mini % 2){
            middle++;
            maxi++;
            ans++;
        }
        ans += (middle-mini)/2;
        ans += (maxi-middle);
    }
    cout << ans << endl;




    return 0;
}
