#include<iostream>
using namespace std;

int main(){

    int n,a,ans=0;;
    cin >> n >> a;

    int tmp = n%500;

    if(tmp <= a){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
