#include<iostream>
using namespace std;

int main(){

    int a,b;
    string s;
    cin >> a >> b >> s;

    if(s[a] == '-'){
        for(int i = 0;i < a-1;i++){
            if(s[i] == '-'){
                cout << "No" << endl;
                return 0;
            }
        }

        for(int i = a+1;i < s.length();i++){
            if(s[i] == '-'){
                cout << "No" << endl;
                return 0;
            }
        }

        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }


    return 0;
}
