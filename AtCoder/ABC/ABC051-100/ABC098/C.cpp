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

typedef long long int ll;

int main(){

    int n;
    string s;
    cin >> n >> s;
    //cout << s << endl;

    vector<int> a(400000,0);
    int ans = INF;

    for(int i = 1;i <= n; i++){

        if(s[i-1] == 'E'){
            a[i]++;
        }
    }
    REP(i,n+1){
        a[i+1] += a[i];
    }



    /*REP(i,n+1){
        cout << a[i] << endl;
    }*/


    int tmp = 0;
    for(int i = 1;i <=s.length();i++){

        tmp = (a[n]-a[i]) + (i-1 - a[i-1]);
        ans = min(ans,tmp);
    }
    cout << ans << endl;

    return 0;
}
