#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


int main(){

    int a,b,c,d;
    cin >> a >> b >> c >> d;
    vector<int> tm(100,0);
   
    for(int i = a;i < b;i++){
        
        tm[i]++;
    }
    for(int i = c;i < d;i++){
    
        tm[i]++;
    }
    int count = 0;
    for(int i = c;i < d;i++){
        
        if(tm[i] == 2){
            count++;
        }
    }
    cout << count << endl;
    
    


    return 0;
}
