int n, m;
std::vector <std::vector <int>> M;
std::vector <int> G[1 + MAXN], SCC;
int pos[1 + MAXN], lowlink[1 + MAXN];
int st[1 + MAXN], instack[1 + MAXN], last;

void print_strongly_connected(){
    printf("%d\n", M.size());
    for(int i = 0; i < M.size(); i++){
        for(int j = 0; j < M[i].size(); j++)
            printf("%d ", M[i][j]);
        printf("\n");
    }
}

void tarjan(int node){
    st[++last] = node;
    instack[node] = 1;
    pos[node] = lowlink[node] = last;
    for(auto y:G[node]){
        if(!pos[y]) tarjan(y), lowlink[node] = std::min(lowlink[node], lowlink[y]);
        else if(instack[y]) lowlink[node] = std::min(lowlink[node], lowlink[y]);
    }

    if(pos[node] == lowlink[node]){
        SCC.clear();
        while(last >= pos[node]){
            SCC.push_back(st[last]);
            instack[st[last]] = 0;
            last--;
        }
        M.push_back(SCC);
    }
}
