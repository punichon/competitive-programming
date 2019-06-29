#include<iostream>
#include<vector>
using namespace std;


int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    int ans = 0;
    bool flag = true;
    while(flag){

        
        for(int i = 0;i < n;i++){
            
            if(a[i] % 2 != 0){
                cout << ans << endl;
                return 0;
            }

            a[i] /=2;
            /*if(a[i] % 2 != 0){
                flag = false;
                break;
            }*/
        }
        ans++;
    }

    cout << ans << endl;
    
    return 0;
}
