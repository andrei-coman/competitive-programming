#define SIGMA 26

int n, k;
struct Trie{
    int word, len;
    Trie *son[SIGMA];
    Trie *fail;
    Trie *wordfail;

    Trie(){
        word = len = 0;
        memset(son, 0, sizeof(son));
    }
};

Trie *T = new Trie();
Trie *S;

inline void bfsFail(){
    std::queue <Trie*> q;
    for(int i = 0; i < SIGMA; i++)
        if(T -> son[i]){
            T -> son[i] -> fail = T;
            T -> son[i] -> wordfail = T;
            q.push(T -> son[i]);
        }

    while(!q.empty()){
        Trie *node = q.front(); q.pop();
        for(int i = 0; i < SIGMA; i++)
            if(node -> son[i]){
                Trie *fail = node;
                do{
                    fail = fail -> fail;
                }while(fail != T && !fail -> son[i]);
                if(fail -> son[i])
                    fail = fail -> son[i];
                node -> son[i] -> fail = fail;
                q.push(node -> son[i]);
            }
        Trie *fail = node -> fail;
        if(!fail -> word)
            fail = fail -> wordfail;
        node -> wordfail = fail;
    }
}

inline void insertAho_fromReader(){
    char c = fgetc(stdin);
    while(c < 'a' || c > 'z') c = fgetc(stdin);
    S = T;
    int len = 0;
    while('a' <= c && c <= 'z'){
        len++;
        c -= 'a';
        if(!S -> son[c])
            S -> son[c] = new Trie();
        S = S -> son[c];
        c = fgetc(stdin);
    }
    S -> word = 1;
    S -> len = len;
}

inline void initializeAho(){
    T -> fail = T -> wordfail = T;
}
