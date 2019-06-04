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
#define INF 1e9
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;

int main(){

    int n,m,x,y;
    cin >> n >> m >> x >> y;
    vector<int> a(n),b(m);

    REP(i,n){
        cin >> a[i];
    }
    VSORT(a);
    REP(i,m){
        cin >> b[i];
    }
    VSORT(b);

    bool exist = false;
    //cout << a[n-1] << b[0] << endl;
    for(int i = x;i <=y;i++){
        //cout << i << endl;
        if(a[n-1] < i && i <= b[0]){
            if(x< i && i <= y){
                exist = true;
            }
        }

    }
    if(exist){
        cout << "No War" << endl;
    }else{
        cout << "War" << endl;
    }







  
  
    return 0;
}
