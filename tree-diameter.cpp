int n;
std::vector <int> G[1 + MAXN];
int depth[1 + MAXN], best;
void dfs(int node, int fth){
    depth[node] = 1 + depth[fth];
    if(depth[node] > depth[best]) best = node;
    for(auto y:G[node]) if(y != fth) dfs(y, node);
}

std::pair <int, int> diameter(){
    best = 0, dfs(1, 0); int A = best;
    best = 0, dfs(A, 0); int B = best;
    return {A, B};
}
