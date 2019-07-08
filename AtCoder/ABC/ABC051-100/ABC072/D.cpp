#include<iostream>
#include<vector>
#include<utility>
using namespace std;


int main(){

    int N,count = 0;;
    cin >> N;

    vector<int>array(N+1,0);
    for(int i = 0;i < N+1;i++){
        cin >> array[i+1];
    }
    for(int i = 0;i < N;i++){
        if(array[i+1] != i+1){
            continue;
        }
        swap(array[i+1],array[i+2]);
        count++;
    }

    cout << count << endl;
    return 0;
}
