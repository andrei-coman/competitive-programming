int n;
std::vector <int> G[1 + MAXN];

int euler[1 + 2 * MAXN], last;
int f[1 + MAXN];
int depth[1 + 1 * MAXN];
void dfs(int node, int papa){
    depth[node] = 1 + depth[papa];
    f[node] = ++last;
    euler[last] = node;
    for(auto y: G[node]) if(y != papa){
        dfs(y, node);
        euler[++last] = node;
    }
}

int lg[1 + 2 * MAXN];
int rmq[1 + MAXLOG][1 + 2 * MAXN];
void buildRMQ(){
    lg[1] = 0;
    for(int i = 2; i <= last; i++) lg[i] = 1 + lg[i / 2];

    for(int i = 1; i <= last; i++) rmq[0][i] = euler[i];
    for(int i = 1; (1 << i) <= last; i++)
        for(int j = 1; j + (1 << i) - 1 <= last; j++){
            if(depth[rmq[i - 1][j]] < depth[rmq[i - 1][j + (1 << (i - 1))]])
                rmq[i][j] = rmq[i - 1][j];
            else
                rmq[i][j] = rmq[i - 1][j + (1 << (i - 1))];
        }
}
int lca(int u, int v){
    int a = f[u], b = f[v];
    if(a > b) std::swap(a, b);
    int len = b - a + 1;
    if(depth[rmq[lg[len]][a]] < depth[rmq[lg[len]][b - (1 << lg[len]) + 1]])
        return rmq[lg[len]][a];
    else
        return rmq[lg[len]][b - (1 << lg[len]) + 1];
}
