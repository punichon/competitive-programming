#include<iostream>
using namespace std;

int main(){

    int a,b,n;
    cin >> a >> b >> n;
    int flag = true;
    while(flag){
        if(n % a == 0 && n % b == 0){
            flag = false;
        }else{
            n++;
        }
    }

    cout << n << endl;

    return 0;
}
