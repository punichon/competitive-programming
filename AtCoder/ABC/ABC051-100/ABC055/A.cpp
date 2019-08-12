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
#define MAX_A 1000000005

int main(){

    int x;
    cin >> x;

    int ans = x*800-200*(x/15);
    cout << ans << endl;


    return 0;
}
