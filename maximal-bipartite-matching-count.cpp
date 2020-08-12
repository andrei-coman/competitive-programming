int n, m, e;
std::vector <int> G[1 + MAXN];
int d[1 + MAXN][1 << (MAXN + 1)];
int c[1 + MAXN][1 << (MAXN + 1)];

inline std::pair <int, int> cntmatching(){
    for(int i = 0; i <= n; i++)
        for(int mask = 0; mask < (1 << m); mask++)
            d[i][mask] = -INF;
    d[0][0] = 0, c[0][0] = 1;

    for(int i = 1; i <= n; i++)
        for(int mask = 0; mask < (1 << m); mask++){
            d[i][mask] = d[i - 1][mask];
            c[i][mask] = c[i - 1][mask];
            for(auto y: G[i]) if(mask & (1 << (y - 1))){
                if(d[i - 1][mask ^ (1 << (y - 1))] + 1 > d[i][mask]){
                    d[i][mask] = d[i - 1][mask ^ (1 << (y - 1))] + 1;
                    c[i][mask] = c[i - 1][mask ^ (1 << (y - 1))];
                }
                else if(d[i - 1][mask ^ (1 << (y - 1))] + 1 == d[i][mask])
                    c[i][mask] += c[i - 1][mask ^ (1 << (y - 1))];
            }
            c[i][mask] %= MOD;
        }

    int cmax = 0, cnt = 0;
    for(int mask = 0; mask < (1 << m); mask++){
        if(d[n][mask] > cmax) cmax = d[n][mask], cnt = c[n][mask];
        else if(d[n][mask] == cmax) cnt += c[n][mask];
    }

    return {cmax, cnt};
}
