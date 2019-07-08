
/*素因数分解*/
template<typename T>
map<T,T> prime_factorization(T m){

    map<T,T> tmp;
    for(T i = 2;i * i <= m;i++){
        while (m % i == 0) {
            tmp[i]++;
            m /= i;
        }
    }
    if(m != 1){
        tmp[m] = 1;
    }
    return tmp;
}


/*拡張ユークリッド*/
template<typename T>
T extgcd(T a,T b,T& x,T& y){
    
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }else{
        T d = extgcd(b,a % b,y,x);
        y -= (a / b) * x;
        return d;
    }
}



//ユークリッド互除法
template<typename T>
T gcd(T x, T y) {

	if (y == 0) {
		return x;
	}
	else {
		return gcd(y, x % y);
	}
}

/*最小公倍数*/
template<typename T>
T lcm(T x, T y) {
	T tmp = gcd(x, y);
	return x * y / tmp;
}



//約数の列挙
template<typename T>
vector<T> divisor(T n) {
	vector<T> res;
	for (T i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			res.push_back(i);
			if (i != n / i) {
				res.push_back(n / i);
			}
		}
	}
	return res;
}




//エラトステネスの篩

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
