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

int aint[8 * MAXN];

int left, right;
int rez;
void query(int p, int st, int dr){
    if(left <= st && dr <= right){
        if(depth[aint[p]] < depth[rez])
            rez = aint[p];
    }
    else{
        int m = (st + dr) / 2;
        if(left <= m) query(2 * p, st, m);
        if(right > m) query(2 * p + 1, m + 1, dr);
    }
}

void build(int p, int st, int dr){
    if(st == dr)
        aint[p] = euler[st];
    else{
        int m = (st + dr) / 2;
        build(2 * p, st, m);
        build(2 * p + 1, m + 1, dr);

        if(depth[aint[2 * p]] < depth[aint[2 * p + 1]])
            aint[p] = aint[2 * p];
        else
            aint[p] = aint[2 * p + 1];
    }
}

void buildLCA(){
    dfs(1, 0);
    build(1, 1, 2 * n);
    depth[0] = 1000000000;
}

int lca(int u, int v){
    left = f[u], right = f[v], rez = 0;
    if(left > right) std::swap(left, right);
    query(1, 1, 2 * n);
    return rez;
}
