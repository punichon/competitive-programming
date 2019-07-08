
struct Bipartite_Matching{
	int n;
	vector<vector<int> > G;
	vector<int> match;
    vector<bool> used;
	
	Bipartite_Matching(){}
	Bipartite_Matching(int siz):n(siz),G(siz),match(siz),used(siz){}
	
    void add_edge(int u,int v){
        G[u].push_back(v);
		G[v].push_back(u);
	}

	bool dfs(int v){
	    used[v] = true;
		for(int i = 0; i < G[v].size();i++){
			int u = G[v][i], w = match[u];
			if(w < 0 || (!used[w] && dfs(w))){
                match[v] = u;
                match[u] = v;
                return true;
			}
        }
        return false;
	}
	int build(){
    	int res = 0;
		fill(match.begin(), match.end(), -1);
		for(int v = 0; v < n; v++){
			if(match[v] < 0){
				fill(used.begin(),used.end(),0);
				if(dfs(v)){
					res++;
				}
			}
		}
		return res;
	}
};