#include<iostream>
using namespace std;


int main(){

    int a,b;

    while(cin >> a >> b){
        int count = 1;
        a += b;
        while(a / 10 != 0){
        a /= 10;
        count++;
    }
    cout << count << endl;
    count = 1;
    }


    return 0;
}
