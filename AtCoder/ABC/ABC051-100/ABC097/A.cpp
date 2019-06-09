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

    int a,b,c,d;
    cin >> a >> b >> c >> d;

    if(abs(a-b)<= d && abs(b-c) < d || abs(a-c) <= d){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
   
    return 0;
}
