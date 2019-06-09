#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include<set>

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

    int k;
    string s;
    cin >> s >> k;

    vector<string> substring;
    for(int i = 0;i < s.size();i++){

        for(int j = 1; i+j <= s.size() && j <= k;j++){
            substring.push_back(s.substr(i,j));
        }
    }

    VSORT(substring);
    set<string> p(substring.begin(),substring.end());
    vector<string> ans(p.begin(),p.end());
    cout << ans[k-1] << endl;

    return 0;
}
