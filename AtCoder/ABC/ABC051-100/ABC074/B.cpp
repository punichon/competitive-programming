#include<iostream>
using namespace std;

int main(){

    int n,k,tmp,length,ans = 0;
    cin >> n >> k;
    for(int i = 0;i < n;i++){
        cin >> tmp;
        length = min(2*tmp,2*(k-tmp));
        ans += length;
    }

    cout << ans << endl;
    return 0;
}
