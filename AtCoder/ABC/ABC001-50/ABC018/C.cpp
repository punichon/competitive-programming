#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include<cstdio>
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
#define MAX_A 105

char mp[505][505];
int a[505][505];
int b[505][505];

int main(){

    int r,c,k;
    cin >> r >> c >> k;
    REP(i,r){
        REP(j,c){
            cin >> mp[i][j];
        }
    }

    REP(i,c){
        int cnt = 0;
        REP(j,r){
            if(mp[j][i] == 'o'){
                cnt++;
            }else{
                cnt = 0;
            }
            a[j][i] = cnt;
        }
        cnt = 0;
        for(int j = r-1;j >= 0;j--){
            if(mp[j][i] == 'o'){
                cnt++;
            }else{
                cnt = 0;
            }
            b[j][i] = cnt;
        }
    }

    int ans = 0;

    for(int x = k-1;x < r-k+1;x++){

        for(int y = k-1;y < c-k+1;y++){

            bool flag = false;
            for(int tmp = 0; tmp < k;tmp++) {
				if(a[x][y - tmp] < k - tmp || a[x][y + tmp] < k - tmp || b[x][y - tmp] < k - tmp || b[x][y + tmp] < k - tmp){ 
					flag = 0;
					break;
				}else{
                    flag = true;
                }
            }
            if(flag){
                ans++;
            }
        }
    }
    cout << ans << endl;



    return 0;
}
