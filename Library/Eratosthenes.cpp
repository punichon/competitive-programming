
/*nまでの素数を列挙して配列に保持*/
vector<ll> Eratosthenes(ll n,vector<ll>& arr){
    
    for(ll i = 0; i < n;i++){
        arr[i] = 1;
    }
    arr[0] = arr[1] = 0;
    for(ll i = 2; i < sqrt(n); i++){
        if(arr[i]){
            for(ll j = 0; i * (j + 2) < n; j++){
                arr[i *(j + 2)] = 0;
            }
        }
    }
    return arr;
}



/*素数のみの配列を返す*/
vector<ll> Eratosthenes(ll n,vector<ll>& arr){
 
    for(ll i = 0; i < n;i++){
        arr[i] = 1;
    }
 
    for(ll i = 2; i < sqrt(n); i++){
        if(arr[i]){
            for(ll j = 0; i * (j + 2) < n; j++){
                arr[i *(j + 2)] = 0;
            }
        }
    }
    vector<ll> prime;
    for(int i = 2;i < arr.size();i++){
        if(arr[i]){
            prime.push_back(i);
        }
    }
    return prime;
}


/*ゴールドバッハの予想、2つの素数の和が与えられたnと一致する組み合わせの個数を求める*/
arr = Eratosthenes(tmp,arr);/*50000までの素数を列挙*/
while(cin >> n,n){
    int count = 0;
    for(int i = 2;i <= n/2;i++){

        if(i <= n-i && arr[i] && arr[n-i]){
            count++;
        }
    }
    cout << count << endl;
}

 /*与えられた正整数 a と d と n に対して，この等差数列に含まれる n 番目の素数を求めるプログラム 
 n<=200を仮定し答えは必ず1e6以下になることが保証*/． 
 int a,d,n;
 int tmp = 1000000;
 vector<int> arr(tmp+1);
 arr = Eratosthenes(tmp,arr);/*50000までの素数を列挙*/    

 while(cin >> a >> d >> n,a){
 
     int count = 0;
     for(int i = a;i < arr.size();i++){
         
        if(arr[i] && ((i-a) % d == 0)){/*素数であり、かつ等差数列上にある数字ならばカウント*/
             count++;
             if(count == n){
                 cout << i << endl;
                 break;
             }
        }
     }

 }  