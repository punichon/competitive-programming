#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include<map>

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

    string ans[7];
    ans[0] = "Do";
	ans[1] = "Re";
	ans[2] = "Mi";
	ans[3] = "Fa";
	ans[4] = "So";
	ans[5] = "La";
    ans[6] = "Si";

    string s[7];
	s[0] = "WBWBWWBWBWBW";
	s[1] = "WBWWBWBWBWWB";
	s[2] = "WWBWBWBWWBWB";
	s[3] = "WBWBWBWWBWBW";
	s[4] = "WBWBWWBWBWWB";
	s[5] = "WBWWBWBWWBWB";
    s[6] = "WWBWBWWBWBWB";
    
    string t;
    cin >> t;
    t = t.substr(0,12);
    int tmp = 0;
    REP(i,7){
        if(t == s[i]){
            tmp = i;
        }
    }
    cout << ans[tmp] << endl;
 

    return 0;
}
