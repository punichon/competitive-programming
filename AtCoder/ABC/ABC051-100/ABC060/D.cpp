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

#define ARRAY_MAX 105


int main(){

    ll n,w,ans = 0;
    cin >> n >> w;
    vector<ll> weight(n),value(n);
    vector<ll> cnt(4,0);//重さ
    vector<ll> v[4];//価値

    REP(i,4){
        cnt[i] = 0;
    }

    REP(i,n){
        cin >> weight[i] >> value[i];
        cnt[weight[i]-weight[0]]++;//各重さの品物が何個あるか数える
        v[weight[i]-weight[0]].push_back(value[i]);//各重さの品物の価値を求める
    }

    sort(v[0].begin(),v[0].end(),greater<ll>());
    sort(v[1].begin(),v[1].end(),greater<ll>());
    sort(v[2].begin(),v[2].end(),greater<ll>());
    sort(v[3].begin(),v[3].end(),greater<ll>());
    //価値の高いものから使う

    REP(a,cnt[0]+1){
        REP(b,cnt[1]+1){
            REP(c,cnt[2]+1){
                REP(d,cnt[3]+1){

                    ll w_sum = 0;
                    ll weight_mini = weight[0];
                    w_sum += a*weight[0] + b*(weight[0]+1) + c*(weight[0]+2) + d*(weight[0]+3);
                    if(w_sum > w){
                        //重さの制約を満たしていない
                        continue;
                    }
                    ll value_sum = 0;
                    REP(i,a){
                        value_sum += v[0][i];
                    }
                    REP(i,b){
                        value_sum += v[1][i];
                    }
                    REP(i,c){
                        value_sum += v[2][i];
                    }
                    REP(i,d){
                        value_sum += v[3][i];
                    }
                    ans = max(ans,value_sum);
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
