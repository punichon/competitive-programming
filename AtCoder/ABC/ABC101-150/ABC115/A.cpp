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
#include<climits>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
using namespace std;
typedef pair<int, int> P;
typedef long long int ll;
typedef pair<ll,ll> LLP;
#define INF 1000000007

#define ARRAY_MAX 200005

int main(){

    ll n;
    cin >> n;
    vector<ll> a(n);
    if(n == 25){
        cout << "Christmas" << endl;
    }else if(n == 24){
        cout << "Christmas Eve" << endl;
    }else if(n == 23){
        cout << "Christmas Eve Eve" << endl;
    }else{
        cout << "Christmas Eve Eve Eve" << endl;
    }



    return 0;
}
