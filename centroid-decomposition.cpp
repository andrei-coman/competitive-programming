std::vector <int> G[1 + MAXN];

int total;
int w[1 + MAXN];
void weight(int node, int fth){
    w[node] = 1;
    total++;
    for(auto y: G[node]) if(y != fth){
        weight(y, node);
        w[node] += w[y];
    }
}

int mainRoot;
void getRoot(int node, int fth){
    if(mainRoot) return;
    int ok = 1;
    if(fth != 0 && total - w[node] > total / 2) ok = 0;
    for(auto y: G[node]) if(y != fth){
        if(w[y] > total / 2) ok = 0;
        getRoot(y, node);
    }
    if(ok) mainRoot = node;
}

void dfs(int node, int fth, int semn){
    ///
}

void proc(int node, int fth){
    ///
}

void centroid(int root){
    total = 0, weight(root, 0);
    if(total == 1){
        ///
        return;
    }
    mainRoot = 0, getRoot(root, 0);

    dfs(mainRoot, 0, +1);
    for(auto y: G[mainRoot]){
        dfs(y, mainRoot, -1);
        proc(y, mainRoot);
        dfs(y, mainRoot, +1);
    }

    dfs(mainRoot, 0, -1);
    int curr = mainRoot;
    for(auto y: G[curr]){
        int z = 0;
        while(G[y][z] != curr) z++;
        std::swap(G[y][z], G[y][G[y].size() - 1]);
        G[y].pop_back();

        centroid(y);
    }
}
