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
#include<climits>

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
typedef long long int ll;
typedef pair<ll,ll> LLP;
#define INF 1000000007

#define ARRAY_MAX 55

ll n,x;
ll b[ARRAY_MAX];
ll p[ARRAY_MAX];
ll cnt[ARRAY_MAX];

ll ans = 0;

void dfs(ll now,ll sum){
    //レベルnを見ている、合計はsum
    sum++;//バンを足す
    if(now == 0){
        ans++;
    }
    if(sum == x){
        return;
    }
    if(sum + cnt[now-1] >= x){
        //n-1レベルのバーガーを食べる過程でxにたどり着く
        dfs(now-1,sum);
    }else{
        //xに足りないので全て足せる
        ans += p[now-1];
        sum += cnt[now-1];

        sum++;//パティ
        ans++;//パティ増加
        if(sum == x){
            //xに達した
            return;
        }else{
            //まだxに達していない
            if(sum + cnt[now-1] >= x){
                //n-1レベルのバーガーを食べる過程でxにたどり着く
                dfs(now-1,sum);
            }else{
                ans += p[now-1];
                sum += cnt[now-1];
            }
            sum++;//バンを足す
        }
    }
}

int main(){

    cin >> n >> x;
    b[0] = 0;
    p[0] = 1;
    cnt[0] = 1;

    /*REP(i,50){
        cout << b[i] << " " << p[i] << endl;
    }*/

    REP(i,51){
        b[i+1] = 2*b[i] + 2;
        p[i+1] = 2*p[i] + 1;
        cnt[i+1] = cnt[i]*2+3;
        //cout << b[i] << " " << p[i] << " " << cnt[i] << endl;
    }
    dfs(n,0LL);//配列添え字に合わせる
    cout << ans << endl;




    return 0;
}
