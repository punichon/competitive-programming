#include<iostream>
using namespace std;


int main(){


    int x,a,b;

    cin >> x >> a >> b;
    int tmp = x-a - (x-a)/b*b;
    cout << tmp << endl;


    return 0;
}
