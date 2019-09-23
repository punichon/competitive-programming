#include<iostream>
#include<algorithm>
using namespace std;

int main(){

    int h1,h2,w1,w2;
    cin >> h1 >> h2 >> w1 >> w2;
    bool flag = false;

    if(h1 == w1 || h1 == w2 || h2 == w1 || h2 == w2){
        flag = true;
    }


    if(flag){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }



    return 0;



}
