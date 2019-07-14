#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int n,k;
    cin >> n >> k;
    vector<int> num(n,0);
    for(int i = 0;i < n;i++){
        cin >> num[i];
    }
    int ans = 0;
    sort(num.begin(),num.end(),greater<int>());
    for(int i = 0;i < k;i++){
        ans+=num[i];
    }

    cout << ans << endl;
    return 0;
}
