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

    int n,tmp,sum=0,ans;
    cin >> n;
    vector<int> place(MAX_A,0);
    for(int i = 1;i <= n+1;i++){
        cin >> place[i];
        sum+=abs(place[i]-place[i-1]);
    }

    for(int i = 1;i <= n;i++){
        int tmp1 = abs(place[i+1]-place[i-1]);
        int tmp2 = (abs(place[i+1]-place[i])+abs(place[i]-place[i-1]));
        //cout << tmp1-tmp2 << endl;
        ans = sum - abs(tmp1-tmp2);
        cout << ans << endl;
    }


    return 0;
}
