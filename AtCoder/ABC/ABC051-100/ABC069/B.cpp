#include<iostream>

using namespace std;


int main(){


    string s;
    cin >> s;
    //cout << s << endl;
    int n = s.length()-2;
    cout << s[0] << n << s[s.length()-1] << endl;;

    return 0;
}
