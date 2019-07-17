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

#define ARRAY_MAX 55
#define MOD 1000000007


int main(){

    int n;
    cin >> n;
    string s;
    cin >> s;

    int a = 0,b = 0;//a:(の数、b:)の数

    for(int i = 0;i < s.length();i++){

        if(s[i] == ')'){
            b++;
            if(a > 0){
                a--;
                b--;
            }
        }else{
            a++;
        }
    }
    string ans;
    REP(i,b){
        ans.push_back('(');
    }
    ans += s;
    REP(i,a){
        ans.push_back(')');
    }
    cout << ans << endl;


    return 0;
}
