#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#include<cstdio>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 1000000007
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;
typedef pair<ll,int> LL_IP;


#define ARRAY_MAX 101

int main(){


    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    double ans = -INF;
    int ans_water,ans_sugar;

    for(int i = 0;100*a*i <= f;i++){
        for(int j = 0;100*a*i+100*b*j <= f;j++){
            for(int k = 0;100*a*i+100*b*j+c*k <= f && c*k <= (a*i+b*j)*e;k++){
                for(int l = 0;100*a*i+100*b*j+c*k+d*l <= f && c*k+d*l <= (a*i+b*j)*e;l++){

                    int water = 100*a*i+100*b*j;
                    int sugar = c*k+d*l;
                    if(ans < 100*sugar/(double)(water+sugar)){
                        ans = 100*sugar/(double)(water+sugar);
                        ans_water = water;
                        ans_sugar = sugar;
                    }


                }
            }
        }
    }
    printf("%d %d\n",ans_water+ans_sugar,ans_sugar);


    return 0;
}
