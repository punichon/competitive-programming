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

    int n,x,tmp,sum = 0,ans;
    cin >> n >> x;
    int mini = 10000000;
    for(int i = 0;i < n;i++){
        cin >> tmp;
        sum+=tmp;
        mini = min(mini,tmp);
    }
    ans = n;
    x-=sum;
    ans += x/mini;
    cout << ans << endl;
   
    return 0;
}
