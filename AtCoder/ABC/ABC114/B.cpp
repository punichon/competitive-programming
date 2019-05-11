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

int main(){

    string s;
    cin >> s;
    ll mini = INF;
    for(int i = 0;i < s.length()-2;i++){

        string t = s.substr(i,3);
        ll tmp = stoi(t);
        mini = min(mini,abs(753LL -tmp));
    }
    cout << mini << endl;


    return 0;
}
