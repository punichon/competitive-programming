#include<iostream>
using namespace std;

#define ARRAY_MAX 100

int main(){

    int times,l,r;
    string s;
    cin >> s;
    cin >> times;
    for(int i = 0;i < times;i++){
        cin >> l >> r;
        //cout << l << r << endl;
        for(int j = 0;j < (r-l+1) /  2;j++){
            swap(s[l-1+j],s[r-1-j]);
        }
        //cout << s << endl;
    }

    cout << s << endl;



    return 0;
}
