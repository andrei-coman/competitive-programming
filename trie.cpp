#define SIGMA 26
#define CH (*s - 'a')

struct Trie{
    int cnt, nrfii;
    Trie *son[SIGMA];

    Trie(){
        cnt = nrfii = 0;
        memset(son, 0, sizeof(son));
    }
};
Trie *T = new Trie;

void trieInsert(Trie *nod, char *s){
    if(*s == '\n')
        nod -> cnt++;
    else{
        if(nod -> son[CH] == 0){
            nod -> son[CH] = new Trie;
            nod -> nrfii++;
        }
        trieInsert(nod -> son[CH], s + 1);
    }
}

int trieDelete(Trie *nod, char *s){
    if(*s == '\n')
        nod -> cnt--;
    else if(trieDelete(nod -> son[CH], s + 1)){
        nod -> son[CH] = 0;
        nod -> nrfii--;
    }
    if(nod -> cnt == 0 && nod -> nrfii == 0 && nod != T){
        delete nod;
        return 1;
    }
    return 0;
}

int trieQuery(Trie *nod, char *s){
    if(*s == '\n')
        return nod -> cnt;
    if(nod -> son[CH])
        return trieQuery(nod -> son[CH], s + 1);
    return 0;
}

int triePrefix(Trie *nod, char *s, int k){
    if(*s == '\n' || nod -> son[CH] == 0)
        return k;
    return triePrefix(nod -> son[CH], s + 1, k + 1);
}
