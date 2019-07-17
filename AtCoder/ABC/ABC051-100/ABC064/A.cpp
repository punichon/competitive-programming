#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    int r,g,b;
    cin >> r >> g >> b;
    int tmp = 100*r+10*g+b;
    if(tmp%4 == 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}
