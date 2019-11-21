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
#include<climits>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
using namespace std;
typedef pair<int, int> P;
typedef long long int ll;
typedef pair<ll,ll> LLP;
#define INF 1000000007

#define ARRAY_MAX 100005
#define MAX_V 100005
#define MAX_LOGV 40

typedef struct LowestCommonAncester{
    //最近共通祖先:木がどの親まで辿れば出会えるのか
    //計算量は各クエリに対してOlog(n)

    int root = 0;
    vector<vector<int> > G;
    vector<vector<int> > parent;
    vector<int> depth;

    void build(int n){
        //配列サイズを初期化
        G.resize(n);
        depth.resize(n);
        parent.resize(MAX_LOGV);
        REP(i,MAX_LOGV){
            parent[i].resize(n);
        }
        REP(i,n){
            depth[i] = 0;
        }
    }

    //引数v,p,dを取り込んで深さ優先探索をする
    void dfs(int v,int p,int d){
        //parent[0][v]（ノードvから1回登ったノード）にpを代入
        parent[0][v]=p;
        //depth[v]（ノードvの深さ）にdを代入
        depth[v]=d;
        //G[v]を順に見て、G[v][i]がpでないなら
        //dfs(G[v][i],v,d+1)を呼ぶ
        //これは、根から順に下に向かってグラフをたどる操作である
        for(int i = 0;i < G[v].size();i++){
            if(G[v][i] != p){
                dfs(G[v][i],v,d+1);
            }
        }
    }
    //初期化
    //Vはノードの数
    void init(int V){
        //根からdfsをはじめる
        //すべてのノードについて、parent[0]とdepthを作る
        dfs(root,-1,0);
        //parentの初期化
        for(int k = 0;k + 1 < MAX_LOGV;k++){
            for(int v = 0;v < V;v++){
                if(parent[k][v] < 0)
                    parent[k+1][v] = -1;
                else
                    parent[k+1][v] = parent[k][parent[k][v]];
            }
        }
    }
    //uとvのLCAを求める
    int lca(int u,int v){
        //uとvの深さが同じになるまで親を辿る
        //uとvの高さを揃える（低いほうを低い分だけ上げる）
        if(depth[u] > depth[v]){
            swap(u,v);
        }
        for(int k = 0;k < MAX_LOGV;k++){
            if(((depth[v]-depth[u])>>k)&1)
                v=parent[k][v];
        }
        //u=vなら、それがLCAであるからvを返す
        if(u == v){
            return v;
        }
        //違うなら、二分探索でLCAを求める
        //u,vが同じになるまで登る
        for(int k = MAX_LOGV - 1;k >= 0;k--){
            if(parent[k][u]!=parent[k][v]){
                u=parent[k][u];
                v=parent[k][v];
            }
        }
        return parent[0][u];
    }

}LCA;

LCA tree;

int main(){

    int n;
    cin >> n;
    tree.build(MAX_V);//配列サイズの初期化
    REP(i,n-1){
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        tree.G[x].push_back(y);
        tree.G[y].push_back(x);
    }
    tree.init(n);//前処理

    int q;
    cin >> q;
    vector<int> ans(q,0);
    REP(i,q){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        ans[i] = tree.depth[a] + tree.depth[b] - 2*tree.depth[tree.lca(a,b)] + 1;
    }
    REP(i,q){
        cout << ans[i] << endl;
    }

    return 0;
}
