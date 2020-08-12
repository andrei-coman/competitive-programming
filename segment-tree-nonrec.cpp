//indexes from 0 to n - 1
int n;
int v[MAXN];
int *tree;

void build(int arr[]){
    tree = new int[2 * n - 1];
    tree--;

    for(int i = 0; i < n; i++)
        tree[n + i] = arr[i];

    for(int i = n - 1; i > 0; i--)
        tree[i] = std::max(tree[i << 1], tree[i << 1 | 1]);
}

void updateTreeNode(int p, int value){
    p += n;
    tree[p] = value;

    while(p > 1){
        p >>= 1;
        tree[p] = std::max(tree[p << 1], tree[p << 1 | 1]);
    }
}

int query(int l, int r){
    l += n;
    r += n + 1;
    int res = -1;
    while(l < r){
        if(l & 1) res = std::max(res, tree[l++]);
        if(r & 1) res = std::max(res, tree[--r]);
        l >>= 1;
        r >>= 1;
    }
    return res;
}
