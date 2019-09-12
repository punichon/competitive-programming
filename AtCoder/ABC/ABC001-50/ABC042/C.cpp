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

    int n,k;
    cin >> n >> k;
    vector<bool> d(10);
    int tmp;
    REP(i,k){
        cin >> tmp;
        d[tmp] = true;
    }
    
    bool flag = true;
    while(flag){
        bool exist = true;;
        vector<int> a(10,0);
        string s = to_string(n);
        //含まれる数字の数え上げ
        REP(i,s.length()){
            a[s[i]-'0']++;
        }
        
        //満たしているか
        REP(i,10){
            if(d[i] == true && a[i] > 0){
                /*これは不適*/
                exist = false;
            }
        }

        if(exist){
            flag = false;
        }else{
            n++;
        }       
    }
    cout << n << endl;
    return 0;
}
