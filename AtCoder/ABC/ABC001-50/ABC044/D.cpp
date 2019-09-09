#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#include<climits>
#include<set>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
typedef pair<ll,ll> pll;
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
#define MOD 1000000007
#define ARRAY_MAX 100005

const ll INF = 1LL << 60;

ll calc(ll b,ll n){

    if(n < b){
        return n;
    }else{
        return calc(b,n/b) + n % b;
    }
}

int main(){

    ll n,s;
    cin >> n >> s;

    if(n < s){
        cout << "-1" << endl;
        return 0;
    }
    if(n == s){
        cout << s+1 << endl;
        return 0;
    }
    ll mini = INF;

    for(ll i = 2;i*i <= n;i++){
        if(calc(i,n) == s){
            mini = min(mini,i);
        }
    }

    if(mini != INF){
        cout << mini << endl;
        return 0;
    }
    //ここからは2 <= b <= sqrt(n)までに解がなかった場合

    for(ll p = 1;p*p < n;p++){

        ll b = (n-s)/p+1;
        if(b == 1){
            //1進数は無視
            //この場合は計算が終わらないので飛ばす
            continue;

        }
        if(calc(b,n) == s){
            mini = min(mini,b);
        }
    }

    if(mini != INF){
        cout << mini << endl;
    }else{
        cout << "-1" << endl;
    }



    return 0;
}
