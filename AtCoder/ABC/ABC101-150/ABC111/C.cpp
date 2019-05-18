#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include<numeric>
#include<map>


#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 999999999
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;

typedef long long int ll;


int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    REP(i,n){
        cin >> a[i];
    }

    map<int,int> odd,even;

    REP(i,n){
        if(i % 2 == 0){
            even[a[i]]++;
        }else{
            odd[a[i]]++;
        }
    }

    int odd_maxi = -INF,odd_maxi_num,odd_second_maxi = 0,odd_second_maxi_num = 0;
    int even_maxi = -INF,even_maxi_num,even_second_maxi = 0,even_second_maxi_num = 0;

    for(auto itr:odd){
        if(odd_maxi < itr.second){
            odd_maxi = itr.second;
            odd_maxi_num = itr.first;
        }
    }

    for(auto itr:even){
        if(even_maxi < itr.second){
            even_maxi = itr.second;
            even_maxi_num = itr.first;
        }
    }
    for(auto itr:odd){
        if(odd_second_maxi < itr.second && itr.first != odd_maxi_num){
            odd_second_maxi = itr.second;
            odd_second_maxi_num = itr.first;
        }
    }
    for(auto itr:even){
        if(even_second_maxi < itr.second && itr.first != even_maxi_num){
            even_second_maxi = itr.second;
            even_second_maxi_num = itr.first;
        }
    }

    int ans = 0;
    

    //cout << odd_maxi << " " << odd_maxi_num << endl;
    //cout << even_maxi << " " << even_maxi_num << endl;
    //cout << odd_second_maxi << " " << odd_second_maxi_num << endl;
    //cout << even_second_maxi << " " << even_second_maxi_num << endl;

    if(odd_maxi_num != even_maxi_num){
        ans = n/2-odd_maxi + n/2-even_maxi;
    }else{
        int tmp = n/2-odd_maxi + n/2-even_second_maxi;
        int tmp2 = n/2-odd_second_maxi + n/2-even_maxi;
        ans = min(tmp,tmp2);
    }
    cout << ans << endl;


    return 0;
}
