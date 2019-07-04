#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include<map>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 999999999
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;
typedef long long int ll;


int n,m;
int a[50],b[50];

bool graph[50][50];
bool visited[50];

void dfs(int v){

    visited[v] = true;
    REP(i,n){

        if(graph[v][i] == false){//隣接していない
            continue;
        }
        if(visited[i] == true){//既に行った
            continue;
        }
        dfs(i);
    }    
}

int main(){

    cin  >> n >> m;

    REP(i,m){
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        graph[a[i]][b[i]] = true;
        graph[b[i]][a[i]] = true;
    }

    int ans = 0;

    REP(i,m){

        graph[a[i]][b[i]] = graph[b[i]][a[i]] = false;//隣接を切る

        REP(j,n){
            visited[j] = false;
        }
        
        dfs(0);

        bool bridge = false;

        REP(j,n){

            if(visited[j] == false){
                bridge = true;
            }
        }

        if(bridge){
            ans++;
        }

        graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
    }
    cout << ans << endl;

    return 0;
}
