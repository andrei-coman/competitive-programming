struct Edge{
    int u, v, valid;
} M[1 + MAXM];
std::vector <int> G[1 + MAXN];
int gr[1 + MAXN];

void ciclu(int node){
    for(auto y: G[node])
        if(M[y].valid){
            M[y].valid = 0;
            if(M[y].u == node) ciclu(M[y].v);
            else ciclu(M[y].u);
        }
    fprintf(fo,"%d ", node);
}
