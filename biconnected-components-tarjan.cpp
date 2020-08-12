int n, m, last;
std::vector <std::vector <int>> M;
std::vector <int> G[1 + MAXN], emptyVec;
std::pair <int, int> S[1 + MAXN];
int depth[1 + MAXN], lowlink[1 + MAXN];

void print_biconnected(){
    printf("%d\n", M.size());
    for(int i = 0; i < M.size(); i++){
        for(auto y: M[i]) printf("%d ", y);
        printf("\n");
    }
}

void writeComponent(int node){
    bool ok = 1;
    M.push_back(emptyVec);
    while(ok){
        if(S[last].second == node) ok = 0;
        M[M.size() - 1].push_back(S[last].first);
        last--;
    }
    M[M.size() - 1].push_back(node);
}

void tarjan(int node, int fth){
    depth[node] = lowlink[node] = depth[fth] + 1;
    for(auto y: G[node]){
        if(!depth[y]){
            S[++last] = {y, node};
            tarjan(y, node);
            lowlink[node] = std::min(lowlink[node], lowlink[y]);
            if(lowlink[y] >= depth[node]) writeComponent(node);
        }
        else lowlink[node] = std::min(lowlink[node], depth[y]);
    }
}
