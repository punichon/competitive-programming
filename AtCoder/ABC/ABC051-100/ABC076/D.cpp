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
#define ARRAY_MAX 205

const int INF = 1e9+7;

double dp[ARRAY_MAX][ARRAY_MAX];

int main(){

    int n;
    cin >> n;
    vector<int> t(n),v(n);
    for(int i = 0;i < n;i++){
        cin >> t[i];
    }
    for(int i = 0;i < n;i++){
        cin >> v[i];
    }
    dp[0][0] = 1;
    for(int number = 0;number < n;number++){//i番目までで
        for(int v_now = 0;v_now <= 105;v_now++){//現在の速さがjの時
            if(v_now > v[number] || dp[number][v_now] == 0){
                continue;
            }
            for(int v_next = 0;v_next <= 105;v_next++){

                if(v_next > v[number]){
                    continue;
                }
                int a = v[number] - v_now;//加速時間
                int b = v[number] - v_next;//減速時間
                if(t[number] < abs(v_now - v_next)){
                    //遷移できない(加減速が間に合わない)
                    continue;                
                }else if(a + b <= t[number]){
                    double up = 1.0*(v[number] *v[number] - v_now * v_now)/2;//加速中
                    double stay = v[number] *(t[number] - a - b);//限界速度で走行
                    double down = 1.0 * (v[number] * v[number] - v_next * v_next)/2;//減速中
                    double len = up + stay + down;//距離の合計
                    dp[number+1][v_next] = max(dp[number+1][v_next],dp[number][v_now] + len);
                
                }else{
                    double x = 1.0 * (t[number] + v_next - v_now)/2;//加速時間
                    double y = 1.0 * (t[number] - v_next + v_now)/2;//減速時間
                    double top = v_now + x;//最高速度


                    double up = 1.0 * (top * top - v_now * v_now)/2;//加速
                    double down = 1.0 *(top * top - v_next * v_next)/2;//減速(台形の面積)
                    double len = up + down;//距離の合計

                    dp[number+1][v_next] = max(dp[number+1][v_next],dp[number][v_now] + len);
                }
            }
        }
    }
    printf("%.9f\n",dp[n][0]-1);

    return 0;
}
