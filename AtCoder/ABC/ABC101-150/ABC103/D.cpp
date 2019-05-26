#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>

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


    int n,m;
    cin >> n >> m;

    vector<pair<int,int> > dem(m);

    for(int i = 0;i < m;i++){
        cin >> dem[i].second >> dem[i].first;
    }

    sort(dem.begin(),dem.end());

    int now = -1;
    int ans = 0;

    for(int i = 0;i < m;i++){
        //cout << dem[i].first << " " << dem[i].second << endl;
        if(dem[i].second > now){
            //cout << "a" << endl;
            ans++;
            now = dem[i].first-1;
            //cout << dem[i].first << " " << dem[i].second << endl;
        }
    }
    cout << ans << endl;

   
    return 0;
}
