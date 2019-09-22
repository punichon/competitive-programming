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

int dx[8] = {1,1,1,0,0,-1,-1,-1};
int dy[8] = {1,0,-1,1,-1,1,0,-1};
 
int main(){

    int h,w;
    cin >> h >> w;
    string s[h];
    bool check[h][w];
    char ans[h][w];
    REP(i,h){
        REP(j,w){
            check[i][j] = false;
            ans[i][j] = '.';
        }
    }

    REP(i,h){
        cin >> s[i];
    }     
    bool exist = true;//解が存在するか
    REP(i,h){
        REP(j,w){
            if(s[i][j] == '.'){
                //マスが'.'なら調べない
                continue;
            }
            //#のあるマスに注目
            bool flag = true;//周りのマスが全て#かどうか、true:全て#
            REP(k,8){
                //8方向に対して行列の範囲内で全て#があるか調べる
                int nx = i + dx[k];
                int ny = j + dy[k];

                if(nx >= 0 && nx < h && ny >= 0 && ny < w){
                   //範囲内にあることの判定
                    if(s[nx][ny] == '.'){
                        flag = false;
                    }
                }
            }
            if(flag){
                ans[i][j] = '#';
                check[i][j] = true;
                //周りが全て#だったのでs[i][j]の周りのマスのcheckをtrueに、ans[i][j]に#を入れる
                REP(k,8){
                    //8方向に対して行列の範囲内で全て#があるか調べる
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx >= 0 && nx < h && ny >= 0 && ny < w){
                       //範囲内にあることの判定
                        check[nx][ny] = true;
                    }
                }
            }
        }
    }

    REP(i,h){
        REP(j,w){
            if(s[i][j] == '#' && check[i][j] == false){
                exist = false;
                break;
            }
        }
    }


    if(exist){
        cout << "possible" << endl;
        REP(i,h){
            REP(j,w){
                cout << ans[i][j];
            }
            cout << endl;
        }
    }else{
        cout << "impossible" << endl;
    }
   


    return 0;
}
