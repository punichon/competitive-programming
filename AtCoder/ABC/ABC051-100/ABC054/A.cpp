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


    int a,b;
    cin >> a >> b;



    if(a > b){
        if(b == 1){
            cout << "Bob" << endl;
        }else{
            cout << "Alice" << endl;
        }
    }else if(a < b){

        if(a == 1){
            cout << "Alice" << endl;
        }else{
            cout << "Bob" << endl;
        }
    }else{
        cout << "Draw" << endl;
    }

    return 0;
}
