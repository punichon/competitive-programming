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
#define MAX_A 101
int main(){


    string s;
    cin >> s;
    int ans = 0;
    int s_len = s.length();

    for(int i = 0;i < s.length()-1;i++){

        if(s[i] != s[i+1]){
            ans++;
        }
    }

    cout << ans << endl;




    return 0;
}
