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
#define ARRAY_MAX 305

const int INF = 1e9+7;


void warshall_floyd(int v,vector<vector<ll> >& d){
    /*頂点の個数、コスト:d[u][v]はe=(u,v)のコスト(存在しない場合はINF,ただしd[i][j]=0とする)*/

    for(int k = 0;k < v;k++){
        for(int i = 0;i < v;i++){
            for(int j = 0;j < v;j++){
                if(i == k || k == j || i == j){
                    continue;
                }
                d[i][j]= min(d[i][j],d[i][k]+d[k][j]);
                //kを通る経路と通らない経路の最小値をとる
            }
        }
    }
}

int main(){

    ll n,m;
    cin >> n >> m;
    vector<vector<ll> > dp(ARRAY_MAX,vector<ll>(ARRAY_MAX,INF));
    for(int i = 0;i < ARRAY_MAX;i++){
        for(int j = 0;j < ARRAY_MAX;j++){
            dp[i][j] = INF;
            if(i == j){
                dp[i][j] = 0;
            }
        }
    }

    vector<pii> vec;
    //1-index
    for(int i = 0;i < m;i++){
        int u,v,l;
        cin >> u >> v >> l;
        u--;
        v--;
        if(u == 0){
            vec.push_back(pii(v,l));
        }else{
            dp[u][v] = dp[v][u] = l;
        }
    }
    warshall_floyd(n,dp);


    ll mini = INF;
    int siz = vec.size();
    for(int i = 0;i < siz;i++){
        for(int j = i+1;j < siz;j++){
            mini = min(vec[i].second + vec[j].second + dp[vec[i].first][vec[j].first],mini);
        }
    }
    if(mini == INF){
        cout << "-1" << endl;
    }else{
        cout << mini << endl;
    }


    return 0;
}
