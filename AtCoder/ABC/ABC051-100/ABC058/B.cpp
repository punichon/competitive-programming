#include<iostream>
using namespace std;


int main(){

    string O,E;
    cin >> O >> E;
    int n = O.length()-E.length();

    if(n == 0){

        for(int i = 0;i < O.length();i++){
            cout << O[i] << E[i];
        }
        cout << endl;
    }else{

        for(int i = 0;i < O.length()-1;i++){
            cout << O[i] << E[i];
        }
        cout << O[O.length()-1] << endl;


    }
    cout << endl;


    return 0;
}
