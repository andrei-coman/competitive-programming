#define SIGMA 26

int n;
char v[1 + MAXN];

struct Trie{
    Trie *son[SIGMA];
    Trie *fail;
    int len;

    Trie(){
        memset(son, 0, sizeof(son));
    }
};
Trie T[1 + MAXN];
int ind;

Trie *S;
Trie *Odd = new Trie();
Trie *Even = new Trie();

inline void initializePalindromicTree(){
    Odd -> fail = Odd;
    S = Odd;
}

inline void insert_fromReader(){
    initializePalindromicTree();
    v[0] = -1, n = 0;
    char c = fgetc(stdin);
    while('a' <= c && c <= 'z'){
        c -= 'a', v[++n] = c;

        while(S != Odd && v[n - S -> len - 1] != c)
            S = S -> fail;
        int flag = 0;
        if(S == Odd){
            if(c == v[n - 1]){
                if(!Even -> son[c]){
                    flag = 1;
                    Even -> son[c] = &T[++ind];
                    Even -> son[c] -> len = 2;
                }
                S = Even -> son[c];
                S -> fail = Odd -> son[c];
            }
            else{
                if(!Odd -> son[c]){
                    flag = 1;
                    Odd -> son[c] = &T[++ind];
                    Odd -> son[c] -> len = 1;
                }
                S = Odd -> son[c];
                S -> fail = Odd;
            }
        }
        else{
            if(!S -> son[c]){
                flag = 1;
                S -> son[c] = &T[++ind];
                S -> son[c] -> len = S -> len + 2;

                Trie *fail = S;
                do{
                    fail = fail -> fail;
                }while(fail != Odd && v[n - fail -> len - 1] != c);
                if(fail == Odd){
                    if(c == v[n - 1])
                        S -> son[c] -> fail = Even -> son[c];
                    else
                        S -> son[c] -> fail = Odd -> son[c];
                }
                else if(fail -> son[c])
                    S -> son[c] -> fail = fail -> son[c];
            }
            S = S -> son[c];
        }
        c = fgetc(stdin);
        ///flag = 1 if there is a new palindrome
    }
}
