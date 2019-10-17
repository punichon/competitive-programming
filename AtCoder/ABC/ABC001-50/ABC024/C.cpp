#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include<numeric>
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
#define ARRAY_MAX 200005
#define MOD 1000000007


int main(){

    int N,D,K;
    cin >> N >> D >> K;
    vector<int> L(D),R(D),S(K),T(K);
    REP(i,D){
        cin >> L[i] >> R[i];
    }
    REP(i,K){
        cin >> S[i] >> T[i];
    }

    REP(i,K){
        int ans = 0;//必要な日数
        //k番目のクエリ
        int now = S[i];//from
        int dest = T[i];//to
        REP(j,D){
            if(L[j] <= now && now <= R[j]){
                //移動できる場合
                if(S[i] < T[i]){
                    //数が増えるほうに進むのならば進めるだけ進める
                    now = R[j];
                    ans++;
                    if(now >= T[i]){
                        //目的地につくか過ぎれば到達とみなす
                        cout << ans << endl;
                        break;
                    }
                }else{
                    //数が減るほうに進めるだけ進める
                    now = L[j];
                    ans++;
                    if(now <= T[i]){
                        cout << ans << endl;
                        break;
                    }
                }
            }else{
                //移動できない場合は1日進める
                ans++;
            }
        }
    }


   
    return 0;
}
