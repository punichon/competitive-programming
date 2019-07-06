#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
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
//#define INF LLONG_MAX / 2;
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;
typedef long long int ll;
typedef pair<ll,int> LL_IP;

const ll INF = LLONG_MAX;

#define ARRAY_MAX 100005
#define INF 1e9+7

typedef struct edge{

    int to;
    int cost;

}EDGE;

void dijkstra(int n,vector<vector<EDGE> >& G,int x,vector<ll>& d){
    /*頂点の個数、辺の情報、始点となる頂点、最短距離の情報*/

    /*最終的にdは経由点からの最短距離が格納される、その過程では暫定的な最短距離が格納され、最短距離が見つかれば、その都度更新される*/

    //vector<ll> d(n,INF);/*最終的な最短距離を保持、初期化はINF*/
    d[x] = 0;
    priority_queue<LL_IP,vector<LL_IP>,greater<LL_IP> > que;/*vectorのpriority_queueで暫定的な最短距離が小さい順に取り出す*/
    que.push(LL_IP(0,x));/*経由点からダイクストラを適用するので経由点の暫定的な最短距離のコストは0*/

    while(!que.empty()){/*queが空になれば最短距離が全て探索できたことになる*/

        LL_IP p = que.top();/*最短距離の１番小さいものの取り出し*/
        que.pop();/*取り出したので調べたとみなし、queから出す*/
        int v = p.second;/*取り出した頂点の番号*/
        if(d[v] < p.first){
            /*取り出した頂点からの最短距離よりも短い経路があるので更新の必要はない*/
            continue;
        }

        for(int i = 0;i < G[v].size(); i++){
            /*取り出した頂点から辺でつながっている頂点への最短距離を調べて現在の値より短ければ更新する*/
            EDGE e = G[v][i];/*取り出した頂点からつながっている頂点を1つ取り出す*/
            if(d[e.to] > d[v] + e.cost){
                /*現在の最短距離よりも、現在の頂点を経由する経路のほうが最短距離が短い場合は最短距離を更新し、次の頂点を調べる*/
                d[e.to] = d[v] + e.cost;/*最短経路の更新*/
                que.push(P(d[e.to],e.to));/*先の頂点を調べるためqueに格納*/
            }
        }
    }
}



int main(){

    int n,m,r,a,b,c;
    cin >> n >> m >> r;

    vector<vector<EDGE> > G(n);/*n個の各頂点からそれ以外の頂点へのコスト*/
    vector<ll> city(r);/*訪れる都市を格納*/
    vector<ll> prev(n);/*最短経路の直前の頂点*/
    vector<ll> d(n,INF);/*最短経路*/
    vector<ll> path;/*経路復元用*/
    vector<bool> visit_city(n,false);/*都市が訪れる対象かどうか*/

    REP(i,r){
        cin >> city[i];
        city[i]--;/*配列の添え字に合わせる*/
        visit_city[city[i]] = true;
    }

    REP(i,m){
        cin >> a >> b >> c;
        a--;
        b--;/*配列の添え字へ合わせる*/
        EDGE e1 = {b,c};
        EDGE e2 = {a,c};
        /*無効グラフなので双方向にコストを保持*/
        G[a].pb(e1);/*頂点aから頂点bへのコストがc*/
        G[b].pb(e2);/*頂点bから頂点aへのコストがc*/
    }
    /*辺の張り終わり*/

    ll ans = INF;
    ll len[205][205];
    ll total[205];/*コストの累積*/

    REP(i,205){
        total[i] = 0;
        REP(j,205){
            len[i][j] = 0;
        }
    }
    
    for(ll i = 0;i < r;i++){
        vector<ll> d(n,INF);/*最短経路*/
        dijkstra(n,G,city[i],d);/*r[i]から各頂点への最短距離を格納した配列*/
        ll cost = 0;
        REP(j,d.size()){
            len[city[i]][j] = d[j];
            len[j][city[i]] = d[j];
        }
    }



    VSORT(city);

    /*REP(i,city.size()){
        cout << city[i] << " ";
    }
    cout << endl;
    */
    do{

        ll tmp_cost = 0;
        for(int i = 0;i < city.size()-1;i++){
            tmp_cost += len[city[i]][city[i+1]];
        }
        /*REP(i,city.size()){
            cout << city[i] << " ";
        }
        cout << tmp_cost << endl;*/
        ans = min(tmp_cost,ans);
    }while(next_permutation(city.begin(),city.end()));




    /*REP(i,n){
        REP(j,n){
            cout << len[i][j];
        }
        cout << endl;
    }*/
    
    cout << ans << endl;

    return 0;
}
