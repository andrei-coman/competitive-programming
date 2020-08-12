int n, m, S, D, flux;
std::vector <int> G[1 + MAXN];
int C[1 + MAXN][1 + MAXN];
int father[1 + MAXN];

int q[1 + MAXN], p, u;
inline bool bfs(){
    memset(father, 0, sizeof(father));
    p = 0, u = 1;
    q[0] = S;
    while(p != u){
        int node = q[p++];
        if(node != D)
            for(auto y:G[node])
                if(!father[y] && C[node][y]) father[y] = node, q[u++] = y;
    }
    return father[D];
}

inline void maximum_flow(int start, int finish){
    S = start, D = finish;
    while(bfs())
        for(auto y:G[D])
            if(father[y] && C[y][D]){
                father[D] = y;
                int flow = 1000000000;
                for(int i = D; i != S && flow; i = father[i]) flow = std::min(flow, C[father[i]][i]);
                if(flow) for(int i = D; i != S; i = father[i]) C[father[i]][i] -= flow, C[i][father[i]] += flow;
                flux += flow;
            }
}
