#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include <numeric>
 
 
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
#define ARRAY_MAX 100005


int main(){

    ll a,b;
    cin >> a >> b;
    string s;

    if(a*b <= 0){
        //0をまたぐ
        s = "Zero";
    }else if(a > 0 && b > 0){
        s = "Positive";
    }else{

        if(abs(b-a) % 2 == 0){
            s = "Negative";
        }else{
            s = "Positive";
        }
    }
    cout << s << endl;

    return 0;
}
