int n, m;
struct Edge{
    int cost, dest;
    bool operator <(const Edge &aux) const{
        return cost > aux.cost;
    }
};
std::vector <Edge> G[1 + MAXN];
int dist[1 + MAXN];
std::priority_queue <Edge> pq;

inline void dijkstra(int src){
    for(int i = 1; i <= n; i++)
        dist[i] = INF;

    pq.push({0, src});
    while(!pq.empty()){
        int node = pq.top().dest, cost = pq.top().cost;
        pq.pop();
        if(dist[node] == INF){
            dist[node] = cost;
            for(auto y: G[node])
                if(dist[y.dest] == INF)
                    pq.push({cost + y.cost, y.dest});
        }
    }
}
