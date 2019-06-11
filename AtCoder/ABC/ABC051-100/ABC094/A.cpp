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

    int a,b,c;
    cin >> a >> b >> c;
    if(a+b>c && a <= c){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
   
    return 0;
}
