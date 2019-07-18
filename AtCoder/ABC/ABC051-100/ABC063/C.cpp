#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define ARRAY_MAX 100

/*dp[i+1][j]:i問目まで解いて得点がj点*/

int n;
int p[ARRAY_MAX+1];
int dp[ARRAY_MAX + 1][ARRAY_MAX*ARRAY_MAX + 1];

void solve(){

    dp[0][0] = 0;/*0問で0点はありえる*/
    for(int i = 0;i < n;i++){
        for(int j = 0;j <= ARRAY_MAX*ARRAY_MAX;j++){
            if(j < p[i]){
                dp[i+1][j] = dp[i][j];//ない
            }else{
                dp[i+1][j] = max(dp[i][j],dp[i][j-p[i]]+p[i]);//解くか解かないか
            }
        }

    }
    
    int ans = 0;
    for(int i = 0;i < ARRAY_MAX*ARRAY_MAX;i++){
        if(dp[n][i] % 10 != 0){/*1なら得点パターンが存在*/
            //cout << "a" << endl;
            ans = max(ans,dp[n][i]);
        }
        //cout << "b" << endl;
    }
    cout << ans << endl;

}

int main(){    

    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> p[i];
    }
    solve();

    return 0;
}
