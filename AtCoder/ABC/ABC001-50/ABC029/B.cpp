#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<map>

#define REP(n) for(int i = 0;i < n;i++)
#define LLREP(n) for(long long int  i = 0;i < n;i++)
typedef long long int ll;
using namespace std;
#define MAX_A 100000

int main(){

    string s;
    int ans = 0;
    REP(12){

        cin >> s;
        if(find(s.begin(),s.end(),'r') != s.end()){
            ans++;
        }
    }
    cout << ans << endl;



    return 0;
}
