#include<iostream>
#include<vector>
using namespace std;



int main(){


    int n;
    cin >> n;
    vector<int> a1(n);
    vector<int> a2(100,0);
    for(int i = 0;i < n;i++){
        cin >> a1[i];
        //cout << a1[i] << endl;
    }

    int ans = 0;
    for(int i = 0;i < n;i++){
        
        if(a2[a1[i]] == 0){
            ans++;
            a2[a1[i]]++;
        }

    }

    cout << ans << endl;



    return 0;
}
