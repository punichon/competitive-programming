#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>

#define REP(n) for(int i = 0;i < n;i++)
#define LLREP(n) for(long long int  i = 0;i < n;i++)
typedef long long int ll;
using namespace std;
#define MAX_A 100

int n,m;
bool map[MAX_A][MAX_A];

int dfs(int now,int n,bool* visited){


    bool all_visited = true;

    for(int i = 0;i < n;i++){
        if(visited[i] == false){
            all_visited = false;
        }
    }

    if(all_visited){
        return 1;
    }

    int r = 0;

    for(int i = 0;i < n;i++){

        if(map[now][i]==false){
            continue;
        }
        if(visited[i]){
            continue;
        }

        visited[i]=true;
        r+=dfs(i,n,visited);
        visited[i] = false;

    }

    return r;
}



int main(){

    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int a,b;
        cin >> a >> b;
        map[a-1][b-1] = true;
        map[b-1][a-1] = true;
    }

    bool visited[MAX_A];

    REP(n){
        visited[i]=false;
    }

    visited[0] = true;

    cout << dfs(0,n,visited) << endl;


    return 0;
}
