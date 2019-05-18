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
#define ARRAY_MAX 3000

const int INF = 1e9+7;

int dp[105][15];

int main(){

    //h+1の全探索O(HK*2^W)
    int h,w,k;
    cin >> h >> w >> k;
    dp[0][0] = 1;
    //dp[h][k]:h列目に来た時に棒の番号がkにいる場合の数

    for(int i = 1;i <= h;i++){

        for(int j = 0;j < w;j++){

            for(int k = 0;k < (1<<(w-1));k++){//橋がどうつながっているか(縦棒 W 本に対して最大(W-1)本の橋)
                
                bool flag = true;

                for(int l = 0;l < w-2;l++){//連続する橋があればこれはあみだくじの条件を満たさないので調べない,(w-2)回調べる
                    if((k >> l) & 1 && (k >> (l+1)) & 1){
                        flag = false;
                    }
                }
                if(flag == true){

                    if(j >= 1 && (k >> (j-1)) & 1){
                        //左にたどる
                        dp[i][j-1] += dp[i-1][j];
                        dp[i][j-1] %= MOD;
                    }else if(j <= w-2 && (k >> j) & 1){
                        //右にたどる
                        dp[i][j+1] += dp[i-1][j];
                        dp[i][j+1] %= MOD;
                    }else{
                        //下にたどる
                        dp[i][j] += dp[i-1][j];
                        dp[i][j] %= MOD;
                    }
                }
            }
        }
    }

    cout << dp[h][k-1] << endl;

    return 0;
}
