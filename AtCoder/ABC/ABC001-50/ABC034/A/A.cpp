#include<iostream>
using namespace std;

int main(){

    int x,y;
    cin >> x >> y;
    int n = x > y ? 1 : 0;
    if(n){
        cout << "Worse" << endl;
    }else{
        cout << "Better" << endl;
    }   
   return 0;
}
