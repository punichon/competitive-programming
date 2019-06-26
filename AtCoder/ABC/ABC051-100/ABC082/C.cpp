#include<iostream>
#include<map>
using namespace std;


int main(){

    map<int,int> m;

    int n;
    cin >> n;
    int tmp;
    int ans = 0;

    for(int i = 0;i < n;i++){
        cin >> tmp;
        m[tmp]++;
    }
    
    map<int,int>::iterator itr;

    for(itr = m.begin();itr != m.end();itr++){
        
        int key = itr->first;
        int value = itr->second;
        if(key < value){
            ans += value - key;
        }else if (key == value){
        
        }else{
            ans += value;
        }

    }

    cout << ans << endl;

    return 0;
}
