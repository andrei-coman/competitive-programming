std::vector <int> G[1 + MAXN];
int viz[1 + MAXN];
int st[1 + MAXN], ind;

void dfs(int node){
    if(viz[node]) return;
    viz[node] = 1;
    for(auto y: G[node])
        dfs(y);
    st[ind++] = node;
}
