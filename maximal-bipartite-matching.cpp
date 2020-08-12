int n, m, edges, x;
std::vector <int> G[1 + MAXN];
int viz[1 + MAXN];
int left[1 + MAXN], right[1 + MAXN];

bool src(int node){
    if(viz[node] == x) return 0;
    viz[node] = x;

    for(auto y: G[node])
        if(!right[y]){
            left[node] = y;
            right[y] = node;
            return 1;
        }
    for(auto y: G[node])
        if(src(right[y])){
            left[node] = y;
            right[y] = node;
            return 1;
        }
    return 0;
}

inline void print_matching(){
    int match = 0;
    for(int i = 1; i <= n; i++)
        if(left[i]) match++;

    printf("%d\n", match);
    for(int i = 1; i <= n; i++)
        if(left[i]) printf("%d %d\n", i, left[i]);
}

inline void matching(){
    x = 1;
    int flag = 1;
    while(flag){
        flag = 0;
        for(int i = 1; i <= n; i++)
            if(!left[i])
                flag = flag | src(i);
        x++;
    }
}
