#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>

#define REP(n) for(int i = 0;i < n;i++)
#define LLREP(n) for(long long int  i = 0;i < n;i++)
typedef long long int ll;
using namespace std;
#define MAX_A 101
int main(){

    int w,h,n,x,y,a;
    cin >> w >> h >> n;
    //ut << w << h << n << endl;

    int ar[MAX_A][MAX_A] = {0};

    int tmp = 0;
    for(int k = 0;k < n;k++){

        cin >> x >> y >> a;
        //cout << x << y << a << endl;
        //cout << "b" << endl;
        if(a == 1){
            //cout << "1" << endl;
            for(int i = 0;i < h;i++){
                for(int j = 0;j < x;j++){
                    if(ar[i][j] != 1){
                        ar[i][j] = 1;
                        tmp++;
                    }
                }
            }
            //cout << tmp << endl;
        }
        //cout << "a" << endl;

        if(a == 2){
            for(int i = 0;i < h;i++){
                for(int j = x;j < w;j++){
                    if(ar[i][j] != 1){
                        ar[i][j] = 1;
                        tmp++;
                    }
                }
            }
            //cout << tmp << endl;
        }

        if(a == 3){
            for(int i = (h-y);i < h;i++){
                for(int j = 0;j < w;j++){
                    if(ar[i][j] != 1){
                        ar[i][j] = 1;
                        tmp++;
                    }
                }
            }
        }

        if(a == 4){
            for(int i = 0;i < (h-y);i++){
                for(int j = 0;j < w;j++){
                    if(ar[i][j] != 1){
                        ar[i][j] = 1;
                        tmp++;
                    }
                }
                //cout << tmp << endl;
            }
            //cout << tmp << endl;
        }
    }
    int count = 0;

    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            if(ar[i][j] == 1){
                count++;
            }
        }
    }

    cout << h*w-count << endl;





    return 0;
}
