int n, m, ans;
int Cost[MAXN][MAXN];
int C[1 << MAXN][MAXN];
std::vector <int> G[MAXN];

inline void hamiltonian(){
    for(int i = 0; i < (1 << n); i++)
		for(int j = 0; j < n; j++) C[i][j] = INF;
	C[1][0] = 0;

	for(int mask = 0; mask < (1 << n); mask++)
	    for(int i = 0; i < n; i++) if(mask & (1 << i))
        	for(auto y: G[i]) if(mask & (1 << y))
            	C[mask][i] = std::min(C[mask][i], C[mask ^ (1 << i)][y] + Cost[y][i]);

	ans = INF;
	for(auto y: G[0])
		ans = std::min(ans, C[(1 << n) - 1][y] + Cost[y][0]);
}
