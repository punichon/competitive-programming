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
#define ARRAY_MAX 10005

const int INF = 1e9+7;

int mp[2005][2005];

int main(){

    int n,k;
    cin >> n >> k;

    int black = 0,sum = 0;
    //sum=白マスの数-黒マスの数
    for(int i = 0;i < n;i++){
        int x,y;
        char c;
        cin >> x >> y >> c;
        x %= 2*k;
        y %= 2*k;
        if(c == 'W'){
            mp[x+1][y+1]++;
            sum++;
        }else{
            mp[x+1][y+1]--;
            sum--;
            black++;
        }

    }

    //二次元いもす（横方向）
    for(int i = 0;i <= 2*k;i++){
        for(int j = 1;j <= 2*k;j++){
            mp[i][j] += mp[i][j-1];
        }
    }
    
    //二次元いもす(縦方向)
    for(int i = 1;i <= 2*k;i++){
        for(int j = 0;j <= 2*k;j++){
            mp[i][j] += mp[i-1][j];
        }
    }

    int ans = -INF;
    for(int i = 0;i <= k;i++){
        for(int j = 0;j <= k;j++){
            //白マスの数(条件を満たすのマスの数)
            int a = mp[i][j];
            int b = mp[i+k][j+k] - mp[i+k][j] - mp[i][j+k] + mp[i][j];
            int c = mp[2*k][j] - mp[i+k][j];
            int d = mp[i][2*k] - mp[i][j+k];
            int e = mp[2*k][2*k] - mp[2*k][j+k] - mp[i+k][2*k] + mp[i+k][j+k];
            int tmp = a + b + c + d + e + black;
            ans = max(ans,max(tmp,n - tmp));
        }
    }
    cout << ans << endl;
    
    return 0;
}
