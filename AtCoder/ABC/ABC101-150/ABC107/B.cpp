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
    vector<string> s(h);
    REP(i,h){
        cin >> s[i];
        //cout << s[i] << endl;
    }

    bool map[h][w];

    REP(i,h){
        REP(j,w){
            map[i][j] = true;
        }
    }


    REP(i,h){
        int white_count = 0;
        REP(j,w){

            if(s[i][j] == '.'){
                white_count++;
            }
            if(white_count == w){
                REP(k,w){
                    map[i][k] = false;
                }
            }
        }
    }

    REP(i,w){
        int white_count = 0;
        REP(j,h){

            if(s[j][i] == '.'){
                white_count++;
            }
            if(white_count == h){
                REP(k,h){
                    map[k][i] = false;
                }
            }
        }
    }

    
    REP(i,h){
        int count = 0;
        REP(j,w){
            if(map[i][j]){
                cout << s[i][j];
                count++;
            }
        }
        if(count != 0){
            cout << endl;
        }
    }



    return 0;
}
