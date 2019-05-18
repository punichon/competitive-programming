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

    int H,W;
    cin >> H >> W;
    int map[H][W];

    REP(i,H){
        REP(j,W){
            cin >> map[i][j]; 
            /*if(map[i][j] == 0){
                count--;
            }*/
        }
        
        
    }
    vector<int> y1,x1,y2,x2;
    

    REP(i,H){
        REP(j,W-1){
            if(map[i][j] % 2 == 1){
                map[i][j]--;
                map[i][j+1]++;
                y1.push_back(i);
                x1.push_back(j);
                y2.push_back(i);
                x2.push_back(j+1);

            }   
        }
    }
    

    REP(i,H-1){
        if(map[i][W-1] % 2 == 0 || map[i][W-1] == 0){

        }else{
            map[i][W-1]--;
            map[i+1][W-1]++;
            y1.push_back(i);
            x1.push_back(W-1);
            y2.push_back(i+1);
            x2.push_back(W-1);
        }
    }

    cout << y1.size() << endl;
    REP(i,y1.size()){
        cout << y1[i]+1 << " " << x1[i]+1 << " " << y2[i]+1 << " " << x2[i]+1 << endl;
    }

  


   
    return 0;
}
