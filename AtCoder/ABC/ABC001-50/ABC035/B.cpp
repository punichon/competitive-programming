#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>

#define REP(n) for(int i = 0;i < n;i++)
#define LLREP(n) for(long long int  i = 0;i < n;i++)
typedef long long int ll;
using namespace std;
#define MAX_A 100000

int main(){

    string s;
    int n,t,k_count = 0;
    int x=0,y=0;
    cin >> s >> t;

    for(int i = 0;i < s.length();i++){

        if(s[i] == 'L'){
            x--;
        }
        if(s[i] == 'R'){
            x++;
        }
        if(s[i] == 'U'){
            y++;
        }
        if(s[i] == 'D'){
            y--;
        }
        if(s[i] == '?'){
            k_count++;
        }
    }

    int ans = 0;
    int tmp = abs(x)+abs(y);
    if(t == 1){
        ans = tmp + k_count;
    }else{
        int len_s = s.length()%2;
        int count = tmp-k_count;
        ans = max(len_s,count);
    }

    cout << ans << endl;
        
    return 0;
}
