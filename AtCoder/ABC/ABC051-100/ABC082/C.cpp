#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){

    int n,k,tmp;
    cin >> n >> k;
    vector<int> a(n+10,0);

    for(int i = 0;i < n;i++){
        cin >> tmp;
        a[tmp]++;
    }

    sort(a.begin(),a.end(),greater<int>());

    int ans = 0;
    for(int i = 0;i < k;i++){
        ans+=a[i];
    }
    cout << n-ans << endl;
    
    return 0;
}
