#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end(),greater<int>());


    int Alice=0,Bob=0;
    for(int i = 0;i<n;i++){
        if(!(i%2)){
            Alice+=a[i];
        }else{
            Bob+=a[i];
        }
    }

    int ans= Alice-Bob;

    cout << ans << endl;


    return 0;
}
