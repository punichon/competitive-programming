#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>

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

    int x1,y1,x2,y2;

    cin >> x1 >> y1 >> x2 >> y2;

    int tmp1 = x2-x1;
    int tmp2 = y2-y1;

    int x3 = x2-tmp2;
    int y3 = y2+tmp1;
    int x4 = x3-tmp1;
    int y4 = y3-tmp2;
    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;


    return 0;
}
