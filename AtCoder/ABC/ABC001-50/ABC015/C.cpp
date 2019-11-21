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

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 1000000000
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;
typedef long long int ll;

#define ARRAY_MAX 10
int n,k;
int sx,sy,gx,gy;
int T[ARRAY_MAX][ARRAY_MAX];
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};

bool dfs(int now,int value){//バグがあるならtrue、バグがないならfalseを返す
    //now問目で現在の値はvalue

    if(now == n){
        //n問目ならn個の選択肢が全て選び終わっている
        if(value == 0){
            //バグがあった
            return true;
        }else{
            //バグはなかった
            return false;
        } 
    }

    for(int i = 0;i < k;i++){//k個目の選択肢まで試す

        if(dfs(now+1,value^T[now][i])){
            //バグがあった
            return true;
        }
    }
    //バグがなかった
    return false;
}


int main(){

    cin >> n >> k;
    REP(i,n){
        REP(j,k){
            cin >> T[i][j];
        }
    }

    if(dfs(0,0)){
        cout << "Found" << endl;
    }else{
        cout << "Nothing" << endl;
    }






    return 0;
}
