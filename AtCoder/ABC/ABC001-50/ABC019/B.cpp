#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<map>
#include<queue>
#include<cstdio>
#include<cmath>

#define REP(n) for(int i = 0;i < n;i++)
#define LLREP(n) for(long long int  i = 0;i < n;i++)
typedef long long int ll;
using namespace std;
#define MAX_A 105

int main(){


    string s,ans;
    cin >> s;
    int i = 0;
    while(i < s.length()){
        cout << s[i];
        int j = i;
        int count = 0;
        for(j = i;j < s.length();j++){
            if(s[j] != s[i]){
                break;
            }else{        
                count++;
            }
        }
        cout << count;
        i = j;
    }
    cout << endl;


    return 0;
}
