int n, m;
int N[1 + MAXN], M[1 + MAXN];

int pi[1 + MAXN];
inline int getPi(){
    pi[1] = 0;
    int k = 0;
    for(int i = 2; i <= n; i++){
        while(k > 0 && N[k + 1] != N[i])
            k = pi[k];
        if(N[k + 1] == N[i]) k++;
        pi[i] = k;
    }
}

int st[1 + MAXN], ind;
inline void KMP(){
    int k = 0;
    for(int i = 1; i <= m; i++){
        while(k > 0 && N[k + 1] != M[i])
            k = pi[k];
        if(N[k + 1] == M[i]) k++;
        if(k == n) st[ind++] = i;
    }
}
