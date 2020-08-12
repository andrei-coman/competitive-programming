int n, m, e;
int S, D;
int flux, total;
std::vector <int> G[1 + MAXN];
int C[1 + MAXN][1 + MAXN], Cost[1 + MAXN][1 + MAXN];
int father[1 + MAXN];

int q[1 + MAXN * MAXN], p, u, inq[1 + MAXN];
int dist[1 + MAXN];
inline void bellman_ford(){
    for(int i = 1; i <= n; i++) dist[i] = INF;
    p = u = 0;
    q[u++] = S, inq[S] = 1, dist[S] = 0;
    while(p < u){
        int node = q[p++];
        inq[node] = 0;
        for(auto y:G[node])
            if(C[node][y] && dist[y] > dist[node] + Cost[node][y]){
                dist[y] = dist[node] + Cost[node][y];
                if(!inq[y]) inq[y] = 1, q[u++] = y;
            }
    }
}

struct Edge{
    int dest, cost;
    bool operator < (const Edge &aux) const{
        return cost > aux.cost;
    }
};
int d[1 + MAXN], reald[1 + MAXN];
std::priority_queue &lt;Edge&gt; pq;
inline bool dijkstra(){
    memset(d, 0x3f, sizeof(d));
    d[S] = 0, reald[S] = 0;
    pq.push({S, 0});
    while(!pq.empty()){
        int node = pq.top().dest, cost = pq.top().cost;
        pq.pop();
        if(d[node] == cost){
            for(auto y: G[node])
                if(C[node][y]){
                    int newd = d[node] + Cost[node][y] + dist[node] - dist[y];
                    if(newd < d[y]){
                        d[y] = newd;
                        reald[y] = reald[node] + Cost[node][y];
                        father[y] = node;
                        pq.push({y, d[y]});
                    }
                }
        }
    }
    memcpy(dist, reald, sizeof(dist));
    return (d[D] != 0x3f3f3f3f);
}

inline void minimum_cost_flow(int start, int finish){
    S = start, D = finish;
    bellman_ford();
    while(dijkstra()){
        int flow = INF, cost = 0;
        for(int i = D; i != S; i = father[i]) flow = std::min(flow, C[father[i]][i]), cost += Cost[father[i]][i];
        for(int i = D; i != S; i = father[i]) C[father[i]][i] -= flow, C[i][father[i]] += flow;
        total += cost * flow;
        flux += flow;
    }
}
