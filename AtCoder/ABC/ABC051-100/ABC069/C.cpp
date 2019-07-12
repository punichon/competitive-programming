#include<iostream>
#include<vector>
using namespace std;

typedef long long int ll;

int main(){


    int n;
    cin >> n;
    //vector<int> a(n);
    int tmp;
    int count = 0;
    int count2 = 0;
    for(int i = 0;i < n;i++){
        cin >> tmp;
        if(tmp%4 == 0){
            count++;
        }else if(tmp % 2 == 0){
            count2++;
        }
    }
    if(count + count2/2 >= n/2){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }


    return 0;
}
