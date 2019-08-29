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
#define MAX_A 1000000007

int main(){

    int n;
    cin >> n;
    string s;
    cin >> s;
    int count = 0,ans = 0;

    REP(n){

        if(s[i] == 'I'){
            count++;
        }else{
            count--;
        }
        ans = max(ans,count);
    }
    cout << ans << endl;

    return 0;
}
