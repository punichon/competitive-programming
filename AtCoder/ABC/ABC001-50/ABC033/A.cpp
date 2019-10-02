#include<iostream>
using namespace std;

int main(){

    string s;
    cin >> s;
    for(int i = 0;i < 3;i++){
        if(s.find(s[i],i+1) == -1){
            cout << "DIFFERENT" << endl;
            return 0;
        }
    }
    cout << "SAME" << endl;
   
   return 0;
}
