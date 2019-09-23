#include<iostream>
using namespace std;

int main(){

    string s;
    cin >> s;
    size_t len = s.length();
    if(s[len-1]=='T'){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;;
    }
       return 0;

}
