#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#include<climits>
#include<set>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
typedef pair<ll,ll> pll;
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
#define MOD 1000000007
#define ARRAY_MAX 100005

const ll INF = 1LL << 60;

void make_str(string& ans,string& s){

    int now = 1;
    int len = s.length();
    for(int i = 1;i < len-1;i++){
        if(s[i] == 'x'){
            //xが来た
            if(ans[now] == 'S'){
                //今見ている文字がSの場合
                if(ans[now-1] == 'S'){
                    //SSW
                    ans.push_back('W');
                }else{
                    //WSS
                    ans.push_back('S');
                }
            }else{
                //今見ている文字がWの場合
                if(ans[now-1] == 'S'){
                    //SWS
                    ans.push_back('S');
                }else{
                    //WWW
                    ans.push_back('W');
                }
            }
        }else{
            //oが来た
            if(ans[now] == 'S'){
                //今見ている文字がSの場合
                if(ans[now-1] == 'S'){
                    //SSS
                    ans.push_back('S');
                }else{
                    //WSW
                    ans.push_back('W');
                }

            }else{
                //今見ている文字がWの場合
                if(ans[now-1] == 'S'){
                    //SWW
                    ans.push_back('W');
                }else{
                    //WWS
                    ans.push_back('S');
                }

            }
        }
        now++;
    }
}

string check(string& ans){

    string vec;
    int len = ans.length();

    for(int i = 0;i < ans.length();i++){
        
        if(i == 0){
            if(ans[i] == 'S'){
                if(ans[len-1] == ans[1]){
                    vec.push_back('o');
                }else{
                    vec.push_back('x');
                }
            }else{
                if(ans[len-1] == ans[1]){
                    vec.push_back('x');
                }else{
                    vec.push_back('o');
                }
            }
        }else if(i == len-1){

            if(ans[i] == 'S'){
                if(ans[i-1] == ans[0]){
                    vec.push_back('o');
                }else{
                    vec.push_back('x');
                }
            }else{
                if(ans[i-1] == ans[0]){
                    vec.push_back('x');
                }else{
                    vec.push_back('o');
                }
            }
        }else{
            if(ans[i] == 'S'){
                if(ans[i-1] == ans[i+1]){
                    vec.push_back('o');
                }else{
                    vec.push_back('x');
                }
            }else{
                if(ans[i-1] == ans[i+1]){
                    vec.push_back('x');
                }else{
                    vec.push_back('o');
                }
            }
        }
    }
    return vec;
}

int main(){

    int n;
    cin >> n;
    string s;
    cin >> s;
    int len = s.length();

    string ans1,ans2,ans3,ans4;
    
    if(s[0] == 'o'){
        ans1 += "SS";
        ans2 += "SW";
        ans3 += "WW";
        ans4 += "WS";
    }else{
        //xの場合
        ans1 += "SS";
        ans2 += "SW";
        ans3 += "WW";
        ans4 += "WS";
    }

    make_str(ans1,s);
    string str1 = check(ans1);
    if(str1 == s){
        cout << ans1 << endl;
        return 0;
    }    

    make_str(ans2,s);
    string str2 = check(ans2);
    if(str2 == s){
        cout << ans2 << endl;
        return 0;
    }
    make_str(ans3,s);
    string str3 = check(ans3);
    if(str3 == s){
        cout << ans3 << endl;
        return 0;
    }

    make_str(ans4,s);
    string str4 = check(ans4);
    if(str4 == s){
        cout << ans4 << endl;
        return 0;
    }

    cout << "-1" << endl;






    return 0;
}
