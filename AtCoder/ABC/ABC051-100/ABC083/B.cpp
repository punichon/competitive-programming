#include<iostream>
using namespace std;

int main(){


    int n,a,b;

    cin >> n >> a >> b;
    int ans = 0;

    for(int i = 1;i <=n;i++){

        int tmp = 0,t=i;
        for(int j = 0;j < 5;j++){
            tmp += t%10;
            t /= 10;
        }
        if(tmp >=a && tmp <= b){
            ans+=i;
        }
       
    }
    cout << ans << endl;

    return 0;

}
