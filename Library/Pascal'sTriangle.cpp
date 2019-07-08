

template<typename T>
T nCr(T n,T r,vector<vector<T> >& c){

    for(T i = 0;i <= n;i++){
        c[i][0] = 1LL;
        for(T j = 1;j <= i;j++){
            c[i][j] = c[i-1][j-1] + c[i-1][j];
        }
    }
    return c[n][r];
}