#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>

#define REP(n) for(int i = 0;i < n;i++)
#define LLREP(n) for(long long int  i = 0;i < n;i++)
typedef long long int ll;
using namespace std;
#define MAX_A 100005

int main(){

    int h,w,n;
    cin >> h >> w >> n;
    int tmp;
    //cout << h << w << n << endl;

    vector<int> a(h*w,0);
    int count1 = 0;//配列
    int count2 = 0;//ループ
    for(int i = 0;i < n;i++){
        cin >> tmp;
        //cout << "a" << endl;
        while(count2 < tmp){
            //cout << "b" << endl;
            a[count1]=i+1;
            count1++;
            count2++;
        }
        count2 = 0;
    }
   /* REP(h*w){
        cout << a[i];
    }
    cout << endl;
*/
    int b[h][w];
   

    int count = 0;
    for(int i = 0;i < h;i++){

        int tmp2 = 0;
        if(i%2 == 0){
            for(int j = i*w;j < (i+1)*w;j++){

                b[i][tmp2]=a[j];
                tmp2++;

            }
            //cout << endl;
        }else{

            for(int j = (i+1)*w-1;j >= i*w; j--){

                b[i][tmp2]=a[j];
                tmp2++;

            }
            //cout << endl;
        }
    }

    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            if(j <=w-2){
                cout << b[i][j] << " "; 
            }else{
                cout << b[i][j];
            }        
        }
        cout << endl;
    }
    return 0;
}
