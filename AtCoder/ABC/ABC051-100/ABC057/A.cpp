#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>

#define REP(n) for(int i = 0;i < n;i++)
typedef long long int ll;
using namespace std;
#define MAX_A 1000000005

int main(){

    int a,b;
    cin >> a >> b;

    int ans = (a+b)%24;
    cout << ans << endl;


    return 0;
}
