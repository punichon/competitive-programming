#include<iostream>

using namespace std;

int main(){

    int n;
    cin >> n;
    int tmp = 1;
    for(int i = 0;tmp <= n;i++){
        tmp*=2;
    }

    cout << tmp/2 << endl;

    return 0;
}
