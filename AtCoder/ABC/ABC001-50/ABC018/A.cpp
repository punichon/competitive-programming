#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

typedef pair<int,int> P;

int main(){

    int a,b,c;
    cin >> a >> b >> c;
    if(a > b && b > c){
        a = 1;
        b = 2;
        c = 3;
    }else if(a > c && c > b){
        a = 1;
        b = 3;
        c = 2;
    }else if(b > a && a > c){
        a = 2;
        b = 1;
        c = 3;
    }else if(b > c && c > a){
        a = 3;
        b = 1;
        c = 2;
    }else if(c > a && a > b){
        a = 2;
        b = 3;
        c = 1;
    }else if(c > b && b > a){
        a = 3;
        b = 2;
        c = 1;
    }

    printf("%d\n%d\n%d\n",a,b,c);
    return 0;
}
