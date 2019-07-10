#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
#define ARRAY_MAX 1000000

string alpha = "abcdefghijklmnopqrstuvxxyz";

int main(){

    string s;
    cin >> s;
    //cout << s << endl;
    vector<char> a(ARRAY_MAX);
    vector<bool> alpha(26);

    for(int i = 0;i < s.length();i++){
        a[i] = s[i];
        //cout << a[i];
    }
    //cout << "h" << endl;


    for(int i = 0;i < alpha.size();i++){
        alpha[i] = false;
    }
    //cout << alpha.size();
    //cout << "j" << endl;
    

    for(int i = 0;i < s.length();i++){
        alpha[a[i]-'a'] = true;
    }
    //cout << "k" << endl;
    
    for(int i = 0;i < alpha.size();i++){
        //cout << "h" << endl;
        if(!alpha[i]){
            //cout << "a" << endl;
            cout << char(i+'a') << endl;
            return 0;
        }
    }

    cout << "None" << endl;

    



    return 0;
}
