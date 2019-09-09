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

    vector<int> a(26,0);
    string s;
    cin >> s;
    REP(s.length()){

        a[s[i]-'a']++;

    }

    bool exist = true;
    REP(26){
        if(a[i]%2 != 0){
            exist = false;
        }
    }
    if(exist){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
   

    return 0;
}
