#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>

#define REP(n) for(int i = 0;i < n;i++)
#define LLREP(n) for(long long int  i = 0;i < n;i++)
typedef long long int ll;
using namespace std;
#define MAX_A 100005

int main(){

    string s; 
    cin >> s;
    int a=0,b=0,c=0;
    for(int i = 0;i < s.length();i++){
        if(s[i] == 'a'){
            a++;
        }
        if(s[i] == 'b'){
            b++;
        }
        if(s[i] == 'c'){
            c++;
        }
    }
    if(a == 1 && b == 1 && c == 1){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}
