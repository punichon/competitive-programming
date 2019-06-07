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
    string s;
    cin >> n >> s;

    int ans = 0;

    for(int i = 0;i < s.length();i++){


        vector<int> tmp1_alpha(26,0),tmp2_alpha(26,0);

        string tmp1 = s.substr(0,i+1);
        string tmp2 = s.substr(i+1,6-tmp1.length());
        
        REP(j,tmp1.length()){
            tmp1_alpha[tmp1[j]-'a']++;
        }
        REP(j,tmp2.length()){
            tmp2_alpha[tmp2[j]-'a']++;
        }

        int count = 0;
        REP(j,26){
            if(tmp1_alpha[j] > 0 && tmp2_alpha[j] > 0){
                count++;
            }
        }

        ans = max(ans,count);

    }

    cout << ans << endl;
    return 0;
}
