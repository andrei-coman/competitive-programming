int n;
int v[1 + MAXN], lg[1 + MAXN];
int rmq[1 + MAXLOG][1 + MAXN];

inline void initializeRMQ(){
    lg[1] = 0;
    for(int i = 2; i <= n; i++) lg[i] = 1 + lg[i / 2];

    for(int i = 1; i <= n; i++) rmq[0][i] = v[i];
    for(int i = 1; (1 << i) <= n; i++)
        for(int j = 1; j + (1 << i) - 1 <= n; j++)
            rmq[i][j] = std::min(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
}

inline int RMQ(int a, int b){
    int len = b - a + 1;
    return std::min(rmq[lg[len]][a],
                    rmq[lg[len]][b - (1 << lg[len]) + 1]);
}
