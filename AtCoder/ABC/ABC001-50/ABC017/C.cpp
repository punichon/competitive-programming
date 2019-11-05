#include<iostream>
#include<vector>
#include<climits>
using namespace std;
#define ARRAY_MAX 1000000

int main(){

    int n,m,l,r,s,sum = 0,ans;
    long long int mini = LLONG_MAX,maxi = -LLONG_MAX;
    cin >> n >> m;
    vector<long long int> num(m+2);
    for(int i = 0;i < n;i++){
        cin >> l >> r >> s;
        num[l] += s;
        num[r+1] -= s;
        sum += s;
    }

    maxi = max(maxi,num[1]);
    mini = min(mini,num[1]);
    for(int i = 2;i < m+1;i++){
        num[i] += num[i-1];
        maxi = max(maxi,num[i]);
        mini = min(mini,num[i]);
    }

    //cout << maxi << " " << mini << endl;

    if(maxi == mini){
        ans = 0;
    }else{
        ans = sum - mini;
    }
 
    cout << ans << endl;

    return 0;
}
   
