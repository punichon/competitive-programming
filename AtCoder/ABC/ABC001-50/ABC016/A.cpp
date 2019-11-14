#include<iostream>
using namespace std;

int main(){

    int m,d;
    cin >> m >> d;
    if(m % d){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }

    return 0;
}
