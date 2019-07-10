#include<iostream>
using namespace std;

int main(){

    int x,a,b;
    cin >> x >> a >> b;
    int distance_A = x>=a ? x-a : a-x;
    int distance_B = x>=b ? x-b : b-x;
    if(distance_A > distance_B){
        cout << 'B' << endl;
    }else{
        cout << 'A' << endl;
    }


    return 0;
}
