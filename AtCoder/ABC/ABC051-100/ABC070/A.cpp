#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


int main(){

    string str,tmp;
    cin >> str;
    tmp = str;

    
    reverse(str.begin(), str.end());
    if(tmp == str){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    //cout << tmp << " " << str << endl;
    
    


    return 0;
}
