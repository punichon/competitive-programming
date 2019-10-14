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
#define EPS 1e-12
#define ARRAY_MAX 25

int a,b,c;
bool check(double middle){

    if(a*middle + b*sin(c*middle*M_PI) < 100.0){
        return true;
    }else{
        return false;
    }
}

double solve(double ok,double ng){


    while(abs(ok-ng) > EPS){
        double middle = (ok+ng)/2;
        if(check(middle)){
            ok = middle;
        }else{
            ng = middle;
        }
    }
    return ok;
}

int main(){

    cin >> a >> b >> c;

    double ng = 1e5;
    double ok = 0;
    double ans = solve(ok,ng);
    printf("%.12f\n",ans);
    
    return 0;
}
