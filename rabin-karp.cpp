#define MOD1 666013
#define MOD2 666019

class Hash{
    public:
    int k = 0, next[1 + MAXN], lista[MOD1];
    int val[1 + MAXN], f[1 + MAXN];
    inline void insert(std::pair &lt;int, int&gt; h){
        k++;
        val[k] = h.second;
        f[k] = 1;
        next[k] = lista[h.first];
        lista[h.first] = k;
    }
    inline void erase(std::pair &lt;int, int&gt; h){
        int ind = h.first;
        int p = lista[ind];
        if(p == 0)
            return;
        if(val[p] == h.second){
            lista[ind] = next[lista[ind]];
            return;
        }
        while(next[p] != 0 && val[next[p]] != h.second)
            p = next[p];
        if(next[p] != 0)
            next[p] = next[next[p]];
    }
    inline int find(std::pair &lt;int, int&gt; h){
        int p = lista[h.first];
        while(p != 0 && val[p] != h.second)
            p = next[p];
        return p;
    }
};
