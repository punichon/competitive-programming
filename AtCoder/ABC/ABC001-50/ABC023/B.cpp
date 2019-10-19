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
#define MAX_A 100000

int main(){

    int n;
    string s;
    cin >> n >> s;

    if(s.length()%2 == 0){
        cout << "-1" << endl;
        return 0;
    }

    string tmp = "b";
    for(int i = 1;i < n/2+1;i++){
        if(i % 3 == 0){
            string p = "b" + tmp + "b";
            tmp = p;
        }else if(i % 3 == 1){
            string p = "a" + tmp + "c";
            tmp = p;
        }else{
            string p = "c" + tmp + "a";
            tmp = p;
        }
    }
    if(tmp == s){
        cout << n/2 << endl;
    }else{
        cout << "-1" << endl;
    }



    return 0;
}
