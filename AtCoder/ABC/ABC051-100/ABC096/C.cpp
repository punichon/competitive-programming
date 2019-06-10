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

    int h,w;
    cin >> h >> w;
    char c[51][51];
    REP(i,51){
        REP(j,51){
            c[i][j] = 'a';
        }
    }

    for(int i = 1;i <= h;i++){
        for(int j = 1;j <= w;j++){
            cin >> c[i][j];
        }
    }

    bool ans = true;
    for(int i = 1;i <= h;i++){
        for(int j = 1;j <= w;j++){
            int count = 0;
            if(c[i][j] == '.'){
                continue;
            }
            if(c[i+1][j] == '#'){
                count++;
            }
            if(c[i-1][j] == '#'){
                count++;
            }
            if(c[i][j+1] == '#'){
                count++;
            }
            if(c[i][j-1] == '#'){
                count++;
            }
            if(count == 0){
                ans = false;
                break;
            }
        }
    }
    if(ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl; 
    }


    return 0;
}
