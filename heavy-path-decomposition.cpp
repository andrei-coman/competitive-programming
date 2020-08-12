int n, m;
std::vector <int> G[1 + MAXN];
int father[1 + MAXN], depth[1 + MAXN], dim[1 + MAXN], big[1 + MAXN];
inline void dfs(int node, int papa){
    father[node] = papa;
    depth[node] = 1 + depth[papa];
    dim[node] = 1;
    for(auto y: G[node]) if(y != papa){
        dfs(y, node);
        dim[node] += dim[y];
        if(dim[y] > dim[big[node]])
            big[node] = y;
    }
}

int head[1 + MAXN];
int pos[1 + MAXN], last;
void heavyDFS(int node, int papaChain){
    pos[node] = ++last;
    head[node] = papaChain;
    if(dim[node] > 1){
        heavyDFS(big[node], papaChain);
        for(auto y: G[node]) if(y != father[node] && y != big[node])
            heavyDFS(y, y);
    }
}

int aint[1 + 4 * MAXN];
int val, poz;
void update(int p, int st, int dr){
    if(st == dr)
        aint[p] = val;
    else{
        int m = (st + dr) / 2;
        if(poz <= m) update(2 * p, st, m);
        else update(2 * p + 1, m + 1, dr);

        if(depth[aint[2 * p]] < depth[aint[2 * p + 1]])
            aint[p] = aint[2 * p];
        else
            aint[p] = aint[2 * p + 1];
    }
}
int left, right, ans;
void query(int p, int st, int dr){
    if(left <= st && dr <= right){
        if(depth[aint[p]] < depth[ans])
            ans = aint[p];
    }
    else{
        int m = (st + dr) / 2;
        if(left <= m) query(2 * p, st, m);
        if(m + 1 <= right) query(2 * p + 1, m + 1, dr);
    }
}
int arbIntMin(int a, int b){
    left = a, right = b, ans = 0;
    query(1, 1, n);
    return ans;
}

int min(int u, int v){
    int answer = 0;
    while(head[u] != head[v]){
        int ans = arbIntMin(pos[head[v]], pos[v]);
        if(depth[ans] < depth[answer]) answer = ans;
        v = father[head[v]];
    }

    int ans = arbIntMin(pos[u], pos[v]);
    if(depth[ans] < depth[answer]) answer = ans;
    return answer;
}

void createHeavy(){
    dfs(1, 0);
    heavyDFS(1, 1);
    depth[0] = INF;
}
