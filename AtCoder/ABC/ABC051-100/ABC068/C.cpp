#include<iostream>
#include<vector>
using namespace std;

#define MAX_A 200001

int main(){

    int n,m;
    cin >> n >> m;
    vector<bool> a(MAX_A,false);//1とi
    vector<bool> b(MAX_A,false);//iとN
    int l,k;
    for(int i = 0;i < m;i++){
        cin >> l >> k;
        if(l == 1){
            a[k] = true;
        }
        if(k == n){
            b[l] = true;
        }
    }

    for(int i = 0;i < n;i++){
        if(a[i] == true && b[i] == true){
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;



    return 0;
}
