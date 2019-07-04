#include<iostream>
#include<algorithm>
#include<cstdio>
#include<climits>
using namespace std;


int main(){

    int h,w;
    cin >> h >> w;
    int count = 0;
    char str[h+2][w+2];
    int num[h+2][w+2] = {0};
    for(int i = 1;i < h+1;i++){
        for(int j = 1;j < w+1;j++){
            cin >> str[i][j];
        }
    }

    /*for(int i = 1;i < h+1;i++){
        for(int j = 1;j < w+1;j++){
           cout << str[i][j];
        }
        cout << endl;
    }*/


    for(int i = 1;i < h+1;i++){
        for(int j = 1;j < w+1;j++){
            if(str[i][j] == '#'){
                num[i][j] = 0;
                if(num[i+1][j-1] != '#'){
                    num[i+1][j-1]++;
                }
                if(num[i+1][j] != '#'){
                    num[i+1][j]++;
                }
                if(num[i+1][j+1] != '#'){
                    num[i+1][j+1]++;
                }
                if(num[i][j-1] != '#'){
                    num[i][j-1]++;
                }
                if(num[i][j+1] != '#'){
                    num[i][j+1]++;
                }
                if(num[i-1][j-1] != '#'){
                    num[i-1][j-1]++;
                }
                if(num[i-1][j] != '#'){
                    num[i-1][j]++;
                }
                if(num[i-1][j+1] != '#'){
                    num[i-1][j+1]++;
                }
            }
        }
    }

    for(int i = 1;i < h+1;i++){
        for(int j = 1;j < w+1;j++){
            if(str[i][j] == '#'){
                cout << '#';
            }else{
                cout << num[i][j];
            }
        }
        cout << endl;
    }

   

    return 0;
}
