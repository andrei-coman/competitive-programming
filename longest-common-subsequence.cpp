int n, m;
int a[1 + MAXN], b[1 + MAXN];
int d[1 + MAXN][1 + MAXN];
int stiva[1 + MAXN], ind;

inline void cmlsc(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(a[i] == b[j]) d[i][j] = 1 + d[i - 1][j - 1];
            else d[i][j] = std::max(d[i - 1][j], d[i][j - 1]);

    int i = n, j = m;
    while(i){
        if(a[i] == b[j]){
            stiva[++ind] = a[i];
            i--, j--;
        }
        else if(d[i - 1][j] < d[i][j - 1]) j--;
        else i--;
    }
}
