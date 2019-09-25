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

    int n,tmp;
    cin >> n;

    map<int,int> mp;
    vector<int> a(n);

    REP(i,n){
        cin >> a[i];
        mp[a[i]] = 0;
    }

    map<int,int>::iterator ite;
    int i = 0;
    for(ite = mp.begin(),i=0;ite != mp.end();ite++,i++){
        ite->second = i;
    }

    /*for(ite = mp.begin(),i=0;ite != mp.end();ite++,i++){
        cout << ite->first << " " << ite->second << endl;
    }*/

    REP(i,n){
        cout << mp[a[i]] << endl;
    }

  
    
  

   
    return 0;
}
