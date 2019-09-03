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

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 1000000000
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;
typedef long long int ll;

#define ARRAY_MAX 101
#define MOD 1000000007

int main(){

    string s;
    cin >> s;
    reverse(s.begin(),s.end());
    bool ans = true;

    string str[4] = {"maerd","remaerd","esare","resare"};

    for(int i = 0;i < s.length();){

        if(s[i] == 'm'){
            if(i+5 > s.length()){
                ans = false;
                break;
            }
            if(s.substr(i,5) != str[0]){
                ans = false;
                break;
            }else{
                i+=5;
            }
        }else if(s[i] == 'r' && s[i+2] == 'm'){
            if(i+7 > s.length()){
                ans = false;
                break;
            }
            if(s.substr(i,7) != str[1]){
                ans = false;
                break;
            }else{
                i+=7;
            }
        }else if(s[i] == 'e'){
            if(i+5 > s.length()){
                ans = false;
                break;
            }
            if(s.substr(i,5) != str[2]){
                ans = false;
                break;
            }else{
                i+=5;
            }
        }else if(s[i] == 'r' && s[i+2] == 's'){
            if(i+6 > s.length()){
                ans = false;
                break;
            }
            if(s.substr(i,6) != str[3]){
                ans = false;
                break;
            }else{
                i+=6;
            }
        }else{
            ans = false;
            break;
        }
    }
    if(ans){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }


    return 0;
}
