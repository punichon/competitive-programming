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

    vector<string> s(3);
    REP(3){
        cin >> s[i];
    }

    int now = 0,next = 0;
    while(!s[now].empty()){

        next = s[now][0]-'a';
        s[now].erase(s[now].begin());
        now = next;
    }

    if(now == 0){
        cout << "A" << endl;
    }else if(now == 1){
        cout << "B" << endl;
    }else{
        cout << "C" << endl;
    }


   

    return 0;
}
