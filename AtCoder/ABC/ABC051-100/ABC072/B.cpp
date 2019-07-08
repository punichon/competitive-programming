#include<iostream>
#include<vector>
using namespace std;

int main(){

    char c;
    int count = 1;
    while(cin >> c){
        if(count % 2){
            cout << c;
        }
        count++;
    }
    cout << endl;

    return 0;
}
