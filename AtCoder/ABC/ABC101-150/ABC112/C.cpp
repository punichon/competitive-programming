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

    vector<ll> x(n),y(n),h(n);
    ll height = 0;

    REP(i,n){
        cin >> x[i] >> y[i] >> h[i];
        if(h[i] != 0){
            //高さ0でないもの
            height = i;
        }
    }

    //i:y j : x
    for(ll i = 0;i <= 100;i++){
        for(ll j = 0;j <= 100;j++){

            ll tmp = h[height] + abs(i - y[height]) + abs(j - x[height]);//仮の高さ
            bool exist = true;

            REP(k,n){
                if(h[k] != max(tmp - abs(x[k]-j) - abs(y[k]-i),0LL)){
                    exist = false;
                    break;
                }
            }
            if(exist){
                //中心座標と高さが正しいものがあった
                cout << j << " " << i << " " << tmp << endl;
                return 0;
            }
        }
    }




    return 0;
}
