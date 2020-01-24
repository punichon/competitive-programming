#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include <numeric>
#include<queue>
 
 
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
typedef pair<ll,int> LL_IP;
#define ARRAY_MAX 100005


int main(){

    int n,m;
    cin >> n >> m;
    vector<int> arr(n,1);
    vector<bool> red(n,false);
    red[0] = true;
  
    REP(i,m){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        if(red[a]){
            //抜き取るほうに赤があるならその次も赤が入る候補
            red[b] = true;
        }
        arr[a]--;//抜いたので減らす
        arr[b]++;//入れたので増やす
        if(arr[a] == 0){
            red[a] = false;
        }
    }
    int ans = 0;
    REP(i,n){
        if(red[i]){
            ans++;
        }
    }
 
    cout << ans << endl;


    return 0;
}

