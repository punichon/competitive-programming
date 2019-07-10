#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cstring>
#include<cmath>
#include <numeric>
#include<queue>
#include<climits>
#include<cstdio>
#include<map>


#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
//#define INF ((LLONG_MAX) / (2))
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;
typedef long long int ll;
typedef pair<ll,int> LL_IP;
typedef pair<ll,ll> LL_LLP;
#define INF 1000000007
#define MAX_H 20000
#define MOD 1000000007


int main(){

    int n;
    cin >> n;
    string s,t,str;
    cin >> s >> t;
    for(int i = 0;i < s.length();){

        if(s[i] == t[i]){
            str.push_back('#');
            i++;
        }else{
            str.push_back('%');
            i += 2;
        }
    }
    //cout << str << endl;
    
    ll ans = 0;
    if(str[0] == '#'){
        ans = 3;
    }else{
        ans = 6;
    }

    for(int i = 1;i < str.size();i++){
        if(str[i-1] == '#'){
            if(str[i] == '#'){
                ans = ans*2%MOD;
            }else{
                ans = ans*2%MOD;
            }
        }else{
            /*前がyの場合*/
            if(str[i] == '%'){
                ans = ans*3%MOD;
            }else{
                ans = ans*1%MOD;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
