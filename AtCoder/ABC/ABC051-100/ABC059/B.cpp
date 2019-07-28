#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>

#define REP(n) for(int i = 0;i < n;i++)
typedef long long int ll;
using namespace std;
#define MAX_A 1000000005

int main(){

    string a,b;
    cin >> a >> b;
    int a_len = a.length();
    int b_len = b.length();

    if(a_len > b_len){
        cout << "GREATER" << endl;
    }else if(a_len < b_len){
        cout << "LESS" << endl;
    }else if(a > b){
        cout << "GREATER" << endl;
    }else if(a < b){
        cout << "LESS" << endl;
    }else{
        cout << "EQUAL" << endl;
    }


    return 0;
}
