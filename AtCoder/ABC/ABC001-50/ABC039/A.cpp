#include<iostream>
using namespace std;

int main(){

    int a,b,c;
    cin >> a >> b >> c;
    int area = 2*(a*b+b*c+c*a);
    cout << area << endl; 

    return 0;
}
