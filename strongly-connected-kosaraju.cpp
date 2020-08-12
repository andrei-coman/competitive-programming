std::vector <int> emptyVec;
std::vector <std::vector <int>> M;
int top[1 + MAXN], last;
bool seen[1 + MAXN];

void sortTop(int node){
    seen[node] = 1;
    for(auto y: G[node])
        if(!seen[y]) sortTop(y);
    top[++last] = node;
}
void dfs(int node){
    seen[node] = 1;
    M.back().push_back(node);
    for(auto y: invG[node])
        if(!seen[y]) dfs(y);
}

void print_strongly_connected(){
    printf("%d\n", M.size());
    for(int i = 0; i < M.size(); i++){
        for(int j = 0; j < M[i].size(); j++)
            printf("%d ", M[i][j]);
        printf("\n");
    }
}

void Kosaraju(){
    for(int i = 1; i <= n; i++)
        if(!seen[i]) sortTop(i);
    memset(seen, 0, sizeof(seen));

    for(int i = n; i >= 1; i--)
        if(!seen[top[i]]){
            M.push_back(emptyVec);
            dfs(top[i]);
        }
}
