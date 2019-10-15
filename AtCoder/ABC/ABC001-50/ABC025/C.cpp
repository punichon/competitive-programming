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
#include<queue>

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
typedef pair<int,P> Pii;
typedef long long int ll;
typedef pair<ll,ll> LLP;
int dx[6] = {1,0,0,-1,1,-1};
int dy[6] = {0,1,-1,0,1,-1};
#define INF 100000007
#define MOD 1000000007
#define ARRAY_MAX 1000005
//const ll INF = 1e17;

int b[2][3];
int c[3][2];
int mp[9];
int naohiro = 0,naoko = 0;
int sum = 0;//全てのスコアの合計
int ans = 0;


int dfs(int turn){

    if(turn == 9){
        int res = 0; 
        REP(i,2){
            REP(j,3){
                if(mp[i*3+j] == mp[(i+1)*3+j]){//縦
                    res += b[i][j];
                }
                if(mp[j*3+i] == mp[j*3+i+1]){//横
                    res += c[j][i];
                }
            }
        }
        return res;
    }else{
        int res = 0;
        REP(i,9){
            if(mp[i] == -1){
                //まだ調べていない
                mp[i] = turn % 2;
                int tmp = dfs(turn+1);
                mp[i] = -1;//もとに戻す
                if(turn%2 == 1){
                    tmp = sum - tmp;
                }
                res = max(res,tmp);
            }
        }
        if(turn % 2 == 0){
            return res;
        }else{
            return sum - res;
        }
    }
}

int main(){

    REP(i,2){
        REP(j,3){
            cin >> b[i][j];
        }
    }

    REP(i,3){
        REP(j,2){
            cin >> c[i][j];
        }
    }

    int turn = 0;
    memset(mp,-1,sizeof(mp));

    REP(i,2){
        REP(j,3){
            sum += b[i][j] + c[j][i];
        }
    }

    ans = dfs(0);//takahashi君のスコア

    cout << ans << endl << sum-ans << endl;


    


    return 0;
}
