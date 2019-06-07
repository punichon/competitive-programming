#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include <numeric>


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

    ll n;
    cin >> n;
    vector<ll> a(n);
    REP(i,n){
        cin >> a[i];
    }

    ll left = 0,right = 1;
    ll bit_now = a[0];
    ll count_now = a[0];
    ll ans = 1;
    //cout << ans << endl;
    while(right < n){
        //cout << right << endl;
        if((bit_now ^ a[right]) == count_now + a[right] || left >= right  ){
            //cout << "a" << endl;
            ans += (right-left+1);
            bit_now = bit_now ^ a[right];
            count_now += a[right];
            right++;
        }else{
            //cout << "b" << endl;
            bit_now = bit_now ^ a[left];
            count_now = count_now - a[left];
            left++;
        }
        //cout << left << " " << right << " " << ans << endl;
    }
    cout << ans << endl;


    return 0;
}
