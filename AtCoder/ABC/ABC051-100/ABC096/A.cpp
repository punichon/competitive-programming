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

    int a,b;
    cin >> a >> b;

    if(b >= a){
        cout << a << endl;
    }else{
        cout << a-1 << endl;
    }

    return 0;
}
