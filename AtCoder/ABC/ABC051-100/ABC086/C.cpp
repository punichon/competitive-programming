#include<iostream>
#include<string>
#include<sstream>
using namespace std;


int main(){

    string a,b;
    cin >> a >> b;
    int x = stoi(a + b);
    
    for(int i = 0;i < 1000;i++){
        if(x == i*i){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;


    return 0;
}
