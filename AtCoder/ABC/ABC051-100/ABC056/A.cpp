#include<iostream>
using namespace std;


int main(){

    char a,b;
    cin >> a >> b;
    bool ans = false;
    if(a == 'H'){
        if(b == 'H'){
            ans = true;
        }else{
            ans = false;
        }
    }else{
        if(b == 'H'){
            ans = false;
        }else{
            ans = true;
        }
    }

    if(ans){
        cout << "H" << endl;
    }else{
        cout << 'D' << endl;
    }



    return 0;
}
