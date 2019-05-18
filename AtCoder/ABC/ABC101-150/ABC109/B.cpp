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

int main(){

    string before,after;
    int n;
    cin >> n;
    cin >> before;
    bool ans = true;
    map<string,int> a;
    a[before]++;
    //cout << a[before] << endl;
    //a.insert(make_pair(before,1));//要素の追加

    REP(i,n-1){
        cin >> after;
        
        if(before[before.length()-1] != after[0]){
            ans = false;
        }
        a[after]++;
        //a.insert(make_pair(after,1));//要素の追加
        before = after;
        //cout << before << ans << endl;
    }

    map<string,int>::iterator ite;
    for(ite = a.begin();ite != a.end();ite++){
        if(ite->second > 1){
            ans = false;
        }
    }

    if(ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}
