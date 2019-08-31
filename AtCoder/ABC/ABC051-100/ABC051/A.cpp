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

    string s;
    cin >> s;
    REP(s.length()){
        if(i == 5 || i == 13){
            cout << " ";
        }else{
            cout << s[i];
        }
    }
    cout << endl;

    return 0;
}
