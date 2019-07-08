
void warshall_floyd(int v,vector<vector<ll> >& d){
    /*頂点の個数、コスト:d[u][v]はe=(u,v)のコスト(存在しない場合はINF,ただしd[i][j]=0とする)*/

    for(int k = 0;k < v;k++){
        for(int i = 0;i < v;i++){
            for(int j = 0;j < v;j++){
                if(i == k || k == j || i == j){
                    continue;
                }
                d[i][j]= min(d[i][j],d[i][k]+d[k][j]);
                //kを通る経路と通らない経路の最小値をとる
            }
        }
    }
}

/*経路に負になる頂点があるかはd[i][i]の正負で判定*/

//以下はテンプレート化したもの
template<typename T> using Matrix = vector<vector<T> >;

template< typename T >
void warshall_floyd(Matrix<T>& g, T inf) {

	for (int k = 0; k < g.size(); k++)
	{
		for (int i = 0; i < g.size(); i++)
		{
			for (int j = 0; j < g.size(); j++)
			{
				if (g[i][k] == inf || g[k][j] == inf)
				{
					continue;
				}
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
}