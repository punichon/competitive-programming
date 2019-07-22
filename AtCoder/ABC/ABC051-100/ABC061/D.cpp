#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cstring>
#include<cmath>
#include <numeric>
#include<queue>
#include<climits>


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

#define INF 1e12+7
#define ARRAY_MAX 2010



typedef struct edge{
    ll from;
    ll to;
    ll cost;
}EDGE;



/*頂点sから各頂点への最短距離を求めること、頂点sから到達できる負閉路があれば真が返る、目的地が決まっているバージョン*/
/*V-1回の更新で各ノードへの最短距離は求められる*/
/*V回目から2V回目までに最短距離が更新される場合は目的地を含む負閉路が存在する*/
bool shortest_path(ll v,ll e,ll s,ll t,vector<EDGE>& arr,vector<ll>& d){
    /*頂点の個数、辺の個数、始点となる頂点、目的地の頂点、辺の情報、最短距離*/
    for(int i = 0;i < d.size();i++){
        d[i] = INF;
    }
    d[s]=0;
    
    for(int i = 0;i < 2*v;i++){
        for(int j = 0;j < e;j++){
            EDGE tmp = arr[j];
            if(d[tmp.from] != INF && d[tmp.to] > d[tmp.from] + tmp.cost){
                d[tmp.to] = d[tmp.from] + tmp.cost;
                if(i >= v-1 && tmp.to == t){
                    return true;
                }

            }
        }
    }
    return false;
}


int main(){

    ll v,e,r,t;/*v:頂点の個数、e:辺の個数、r:始点となる頂点の番号*/
    cin >> v >> e;
    vector<EDGE> arr(ARRAY_MAX);/*辺の情報を格納*/
    vector<ll> d(ARRAY_MAX,0);/*負の閉路があるかの判定、0で初期化*/
   
    REP(i,e){
        cin >> arr[i].from >> arr[i].to >> arr[i].cost;
        arr[i].from--;
        arr[i].to--;/*配列添え字に合わせる*/
        arr[i].cost = -arr[i].cost;
    }

   
    bool exist_negative_cycle = shortest_path(v,e,0,v-1,arr,d);

    if(exist_negative_cycle){
        /*負の閉路が存在する場合*/
        cout << "inf" << endl;
    }else{
        cout << -d[v-1] << endl;
    }

    return 0;
}
