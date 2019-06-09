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

    int x;
    cin >> x;
    int ans = 1;
    for(int i =1;i <= x;i++){
        for(int j = 2;j <= x;j++){
            if(pow(i,j)<= x){
                ans = max(ans,(int)pow(i,j));
            }
            
        }
        //cout << ans << endl;
    }
    cout << ans << endl;

   
    return 0;
}
