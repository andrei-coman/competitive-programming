class Hash{
    public:
    int k = 0, next[1 + MAXN], lista[MOD];
    int val[1 + MAXN], f[1 + MAXN];
    inline void insert(int element){
        k++;
        val[k] = element;
        f[k] = 1;
        next[k] = lista[element % MOD];
        lista[element % MOD] = k;
    }
    inline void erase(int element){
        int ind = element % MOD;
        int p = lista[ind];
        if(p == 0)
            return;
        if(val[p] == element){
            lista[ind] = next[lista[ind]];
            return;
        }
        while(next[p] != 0 && val[next[p]] != element)
            p = next[p];
        if(next[p] != 0)
            next[p] = next[next[p]];
    }
    inline int find(int element){
        int p = lista[element % MOD];
        while(p != 0 && val[p] != element)
            p = next[p];
        return p;
    }
};
