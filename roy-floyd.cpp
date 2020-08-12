int n;
int d[1 + MAXN][1 + MAXN];

inline void roy_floyd(){
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(d[i][k] && d[k][j] && i != j && (!d[i][j] || d[i][j] > d[i][k] + d[k][j]))
                    d[i][j] = d[i][k] + d[k][j];
}
