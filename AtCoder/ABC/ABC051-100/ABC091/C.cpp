#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cstring>
#include<cmath>
#include<numeric>
#include<queue>
#include<climits>
#include<cstdio>
#include<map>


#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
//#define INF ((LLONG_MAX) / (2))
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;
typedef long long int ll;
typedef pair<ll,int> LL_IP;
typedef pair<ll,ll> LL_LLP;
#define INF 1000000007
#define MAX_H 20000
#define MOD 1000000007

typedef struct area{

    int x;
    int y;
    bool color;//true:赤
    bool used;

}AREA;

bool comp(const AREA& a,const AREA& b){
    return a.x < b.x;
}

int main(){

    int n,ans = 0;
    cin >> n;
    vector<AREA> a,b;

    REP(i,n){
        AREA e;
        cin >> e.x >> e.y;
        e.color = true;
        e.used = false;//使われていないとする
        a.push_back(e);
    }

    REP(i,n){
        AREA e;
        cin >> e.x >> e.y;
        e.color = false;
        e.used = false;
        b.push_back(e);
    }
    sort(b.begin(),b.end(),comp);

    /*REP(i,n){
        cout << a[i].x << " " << a[i].y << endl;
    }*/

    for(int i = 0;i < n;i++){
        /*i番目の青を見る*/
        int maxi = -INF;
        int index = -1;
        for(int j = 0;j < n;j++){
            //赤を見る
            if(a[j].x < b[i].x && a[j].y < b[i].y && a[j].color == true && a[j].used == false){
                if(maxi < a[j].y){
                    maxi = a[j].y;
                    index = j;
                }
            }
        }
        //cout << i << index << endl;
        if(index != -1){
            //ペアができる
            a[index].used = true;
            ans++;
        }
    }
    cout << ans << endl;
    
    return 0;
}
