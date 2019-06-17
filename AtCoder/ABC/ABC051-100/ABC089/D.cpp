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
#define MAX_A 1000000


typedef struct place{
    int hori;
    int ver;
}PLACE;

int map[301][301];


int main(){

    
    
    int h,w,d,q;
    cin >> h >> w >> d;
    int num[h*w+1];
    int D[900001] = {0};
    PLACE now[h*w+1];

    for(int i =0;i < h;i++){
        for(int j = 0;j < w;j++){
            cin >> map[i][j];
            now[map[i][j]].hori = i+1;
            now[map[i][j]].ver = j+1;
        }
    }

    cin >> q;

    int l,r;


    for(int i = d+1;i <= h*w;i++){

        D[i] = D[i-d]+ abs(now[i].hori - now[i-d].hori) + abs(now[i].ver - now[i-d].ver);

    }

    for(int i = 0;i < q;i++){
        cin >> l >> r;
        cout << D[r]-D[l] << endl;
    }
   











    return 0;
}
