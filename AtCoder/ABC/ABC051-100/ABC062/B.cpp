#include<iostream>
#include<vector>
#include<algorithm>

#define REP(n) for(int i = 0;i < n;i++)
using namespace std;

int main(){

    int h,w;
    cin >> h >> w;
    //cout << "ab" << endl;

    vector<string> P(h);
    //cout << "h" << endl;
    REP(h){
        //cout << "in" << endl;
        cin >> P[i];
    }
    //cout << "a" << endl;
    REP(w+2){
        cout << "#";
    }
    cout << endl;

    
    REP(h){
        cout << '#' << P[i] << '#' << endl;
    }
    REP(w+2){
        cout << '#';
    }
    cout << endl;





    
   
    return 0;
}
