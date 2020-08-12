int n, m, cost;
struct Edge{
    int left, right, cost;
} M[1 + MAXM];
int cmpM(Edge A, Edge B){return A.cost < B.cost;}
int st[1 + MAXN], ind = 0;

int father[1 + MAXN];
inline int Union(int a, int b){
    father[b] = a;
}
int Find(int x){
    if(father[x] == x)
        return x;
    return father[x] = Find(father[x]);
}

inline void print_tree(){
    printf("%d\n%d\n", cost, n - 1);
    for(int i = 1; i <= ind; i++)
        printf("%d %d\n", M[st[i]].left, M[st[i]].right);
}

inline void minimal_spanning_tree(){
    std::sort(M + 1, M + m + 1, cmpM);
    for(int i = 1;i <= n; i++)
        father[i] = i;
    for(int i = 1; i <= m; i++){
        if(Find(M[i].left) != Find(M[i].right)){
            Union(Find(M[i].left), Find(M[i].right));
            cost += M[i].cost;
            st[++ind] = i;
        }
    }
}
