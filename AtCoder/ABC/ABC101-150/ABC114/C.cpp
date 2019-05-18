#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include<cstdio>
#include<map>
#include<set>
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


ll n;
ll a[3] = {3,5,7};
ll ans = 0;
string tmp;
ll len;

void dfs(ll now,ll num){
    //now桁目

    //cout << now << " " << num << endl;
    string t = to_string(num);
    bool three = false,five = false,seven = false;
    if(num > n || t.length() > len){
        //大きいならreturn
        return;
    }

    //nより小さい場合、357があるか調べる
    REP(i,t.length()){
        if(t[i] == '3'){
            three = true;
        }
        if(t[i] == '5'){
            five = true;
        }
        if(t[i] == '7'){
            seven = true;
        }
    }

    if(three && five && seven){
        //357全てある、この時必ずnum<=nは成り立っている
        ans++;
    }

    for(int i = 0;i < 3;i++){
        dfs(i+1,num*10+a[i]);
    }
    return;
}


int main(){

    cin >> n;
    tmp = to_string(n);
    len = tmp.length();
    dfs(0,0);
    cout << ans << endl;

    return 0;
}
