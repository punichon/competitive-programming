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
#include<queue>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 1000000007
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;
typedef long long int ll;
ll dx[4] = {1,0,0,-1};
ll dy[4] = {0,1,-1,0};

#define ARRAY_MAX 1005

int main(){

    string s;
    cin >> s;

    if(s.length() == 2 && s[0] == s[1]){
        cout << "1 2" << endl;
        return 0;
    }

    ll first,last;
    REP(i,s.length()-2){

        string t = s.substr(i,3);
        map<char,int> mp;
        REP(j,t.length()){
            mp[t[j]]++;
        }
        for(auto itr:mp){
            if(itr.second >= 2){
                first = i+1;
                last = i+1+2;
                cout << first << " " << last << endl;
                return 0;
            }
        }
    }

    cout << "-1 -1" << endl;

    return 0;
}
