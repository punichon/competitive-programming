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
#define ARRAY_MAX 305

const ll INF = 1e17+7;
const ll MOD = 1e9+7;


void warshall_floyd(int v,vector<vector<ll> >& d){
    /*頂点の個数、コスト:d[u][v]はe=(u,v)のコスト(存在しない場合はINF,ただしd[i][j]=0とする)*/

    for(int k = 0;k < v;k++){
        for(int i = 0;i < v;i++){
            for(int j = 0;j < v;j++){
                if(i == k || k == j || i == j){
                    continue;
                }
                d[i][j]= min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}


vector<vector<ll> > mp(ARRAY_MAX,vector<ll>(ARRAY_MAX,0));
vector<vector<bool> > memo(ARRAY_MAX,vector<bool>(ARRAY_MAX,true));

int main(){

    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> mp[i][j];
        }
    }

    ll ans = 0;
    for(int k = 0;k < n;k++){
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                
                if(i == k || j == k){
                    //頂点Eから頂点Eへする場合は飛ばす
                    continue;
                }
                if(mp[i][j] > mp[i][k] + mp[k][j]){
                    //最短路（もっといいもの）があるのでこのようなグラフは存在しない
                    cout << "-1" << endl;
                    return 0; 
                }
                if(mp[i][j] == mp[i][k] + mp[k][j]){
                    //他の経路を使用したほうが最適な場合は道はいらない
                    memo[i][j] = false;
                }
            }
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(memo[i][j]){
                ans += mp[i][j];
            }
        }
    }
    cout << ans/2 << endl;//２回数えているので2で割る

    return 0;
}
