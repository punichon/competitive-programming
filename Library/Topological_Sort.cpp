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

#define ARRAY_MAX 105

void dfs(int now,vector<vector<int> >& g,vector<bool>& used,vector<int>& ans){

    used[now] = true;//今いる位置をチェックする
    for(auto to : g[now]){
        if(used[to] > 0){
            //既に調べたならもう見ない
            continue;
        }
        dfs(to,g,used,ans);
    }
    //帰りがけ順で追加
    ans.push_back(now+1);
}

//トポロジカルソート
void Topological_Sort(int v,int e,vector<vector<int> >& g,vector<bool>& used,vector<int>& ans){
    //頂点数、辺の個数、隣接リスト、チェック用配列、結果用配列

    for(int i = 0;i < v;++i){
        if(used[i] == true){
            //既に調べているなら見ない
            continue;
        }
        dfs(i,g,used,ans);
    }
    reverse(ans.begin(),ans.end());
}


int main(){

    int m,n;//頂点数、辺の個数
    cin >> m >> n;
    vector<vector<int> > g(ARRAY_MAX);//隣接リスト
    vector<bool> used(ARRAY_MAX,false);//そのノードを使用したかどうかの判定
    vector<int> ans;//トポロジカルソートの結果配列

    REP(i,n){
        int x,y;
        cin >> x >> y;
        x--;
        y--;//indexによってはいらない可能性あり
        g[x].push_back(y);
    }

    Topological_Sort(m,n,g,used,ans);
    REP(i,ans.size()){
        cout << ans[i] << endl;
    }  


    return 0;
}