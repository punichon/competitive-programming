#include<iostream>
using namespace std;

int main(){

    string s1,s2;
    cin >> s1 >> s2;
    size_t s1_len = s1.length();
    size_t s2_len = s2.length();
    if(s1_len > s2_len){
        cout << s1 << endl;
    }else{
        cout << s2 << endl;
    }
    
    return 0;
}
