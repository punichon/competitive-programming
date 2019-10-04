#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include<cstdio>
#include <numeric>
 
 
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
#define ARRAY_MAX 100005
#define MAX_A 105
 
int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    REP(i,n){
        cin >> a[i];
    }

    int ans = -INF;
    REP(i,n){
        int maxi_taka = -INF,maxi_ao = -INF;//iおける得点の最大値
        REP(j,n){
            if(i == j){
                continue;
            }
            int taka = 0,ao = 0,count = 0;
            FOR(k,min(i,j),max(i,j)+1){
                //選択した区間における得点
                if((count)%2 == 0){
                    taka += a[k];
                }else{
                    ao += a[k];
                }
                count++;
            }
            if(ao > maxi_ao){
                maxi_taka = taka;
                maxi_ao = ao;
            }
        }
        ans = max(ans,maxi_taka);
    }
   
    cout << ans << endl;
    


    return 0;
}
