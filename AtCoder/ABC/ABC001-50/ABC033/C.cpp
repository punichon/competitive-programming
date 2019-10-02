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

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 1000000000
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;
typedef long long int ll;

#define ARRAY_MAX 505

int main(){

    string s;
    cin >> s;
    vector<string> str;

    int left = 0;
    REP(i,s.length()){

        if(s[i] == '+'){
            str.push_back(s.substr(left,i-left));
            left = i+1;
        }
    }
    str.push_back(s.substr(left,s.length()-left));

    ll ans = 0;
    REP(i,str.size()){
        if(find(str[i].begin(),str[i].end(),'0') == str[i].end()){
            ans++;
        }
    }
    cout << ans << endl;




    return 0;
}
