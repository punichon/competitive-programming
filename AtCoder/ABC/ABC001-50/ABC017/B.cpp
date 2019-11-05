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


    string s;
    cin >> s;
    bool choku = true;
    REP(s.length()){
        //cout << s[i] << endl;
        if(s[i] == 'c'){
            if(s[i+1] == 'h' && i <= s.length()-2){

            }else{
                choku = false;
            }
        }else if(s[i] == 'h'){
            if(s[i-1] == 'c' && i > 0){

            }else{
                choku = false;
            }
        }else if(s[i] == 'k' || s[i] == 'o' || s[i] == 'u'){

        }else{
            choku = false;
        }
    }

    if(choku){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}
