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
#include<queue>

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
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;
typedef long long int ll;
ll dx[4] = {1,0,0,-1};
ll dy[4] = {0,1,-1,0};

#define ARRAY_MAX 1005
typedef pair<ll,int> LL_IP;


typedef struct edge{

    int to;
    int cost;

}EDGE;

void dijkstra(int n,vector<vector<EDGE> >& G,int x,vector<ll>& d){
    /*頂点の個数、辺の情報、始点となる頂点、直前の頂点の情報、最短距離の情報*/

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

    int n,m,a,b;
    cin >> n >> m;
    vector<vector<EDGE> > G(n);/*n個の各頂点からそれ以外の頂点へのコスト*/
    
    REP(i,m){
        cin >> a >> b;
        a--;
        b--;/*配列の添え字へ合わせる*/
        EDGE e1 = {b,1};
        EDGE e2 = {a,1};
        /*無効グラフなので双方向にコストを保持*/
        G[a].pb(e1);/*頂点aから頂点bへのコストがc*/
        G[b].pb(e2);/*頂点bから頂点aへのコストがc*/
    }
    /*辺の張り終わり*/

    REP(i,n){
        vector<ll> d(n,INF);/*最短経路*/
        dijkstra(n,G,i,d);/*経由点から各頂点への最短距離を格納した配列*/
        d.shrink_to_fit();

        ll ans = 0;

        REP(j,d.size()){
            if(d[j] == 2){
                ans++;
            }
        }
        cout << ans << endl;
    }


    return 0;
}
