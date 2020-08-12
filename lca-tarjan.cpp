int n;
std::vector <int> G[1 + MAXN];
struct Query{int index, node;};
std::vector <Query> Q[1 + MAXN];

int father[1 + MAXN];
inline void Union(int x, int y){
    father[y] = x;
}
inline int Find(int x){
    if(father[x] == 0)
        return x;
    return father[x] = Find(father[x]);
}

bool color[1 + MAXN];
int ans[1 + MAXQ];
void dfs(int node, int papa){
    for(auto y: G[node]) if(y != papa){
        dfs(y, node);
        Union(node, y);
    }
    color[node] = 1;
    for(auto y: Q[node]) if(color[y.node])
        ans[y.index] = Find(y.node);
}
