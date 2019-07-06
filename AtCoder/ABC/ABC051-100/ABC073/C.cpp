#include<iostream>
#include<cstdio>
#include<set>
using namespace std;

int main(){

    int N,count = 0;
    cin >> N;
    long long int A;
    set<long long int> number;
    set<long long int>::iterator ite;

    for(int i = 0;i < N;i++){

        cin >> A;
        ite = number.find(A);
        if(ite == number.end()){
            number.insert(A);
            count++;
        }else{
            count--;
            number.erase(A);
        }
    }
    
    cout << count << endl;

    return 0;
}
