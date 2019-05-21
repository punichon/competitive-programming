#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>

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

int main(){

    int n;
    cin >> n;
    int ans = 0;
    if(n < 105){
        ans = 0;
    }else if(n >= 105 && n < 135){
        ans = 1;
    }else if(n >= 135 && n < 165){
        ans = 2;
    }else if(n >=165 && n < 189){
        ans = 3;
    }else if(n>= 189 && n <195){
        ans = 4;
    }else{
        ans = 5;
    }
    cout << ans << endl;

    return 0;
}
