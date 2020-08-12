int n, m;
struct Edge{
    int node, cost;
};
std::vector <Edge> G[1+MAXN];
int dist[1 + MAXN], app[1 + MAXN], inq[1 + MAXN];
std::queue <int> q;

inline bool bellman_ford(){
    int noCycle = 1;
    for(int i = 1; i <= n; i++)
        dist[i] = INF;

    q.push(1);
    dist[1] = 0, inq[1] = 1;
    while(!q.empty() && noCycle){
        int node = q.front();
        q.pop();
        inq[node] = 0;
        for(auto y: G[node])
            if(dist[node] + y.cost < dist[y.node]){
                dist[y.node] = dist[node] + y.cost;
                app[y.node]++;
                if(app[y.node] == n)
                    noCycle = 0;
                if(!inq[y.node]){
                    inq[y.node] = 1;
                    q.push(y.node);
                }
            }
    }
    return noCycle;
}
