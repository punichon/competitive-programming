#include<iostream>
#include<cstdio>
using namespace std;

int main(){

    long long int m;

    cin >> m;

    if(m < 100){
        cout << "00" << endl;
    }else if(m >= 100 && m <= 5000){
        if(m < 1000){
            printf("%02lld\n",m / 100);
        }else{
            printf("%2lld\n",m / 100);
        }
    }else if(m >= 6000 && m <= 30000){
        printf("%2lld\n",m / 1000 + 50);
    }else if(m >= 35000 && m <= 70000){
        printf("%2lld\n",(m / 1000 - 30) / 5 + 80);
    }else{
        printf("89\n");
    }
    return 0;
}
