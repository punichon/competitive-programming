#include<iostream>
using namespace std;

int main(){

    int a,b,ans;
    cin >> a >> b;
    if(b % a == 0){
        ans = b / a;
    }else{
        ans = b / a + 1;
    }
    cout << ans << endl;


    return 0;
}
