int n, m;
char N[1 + 2 * MAXN];
int Z[1 + 2 * MAXN];
int st[1 + MAXN], last;

inline void Z_algorithm(){
    n += m;
    int L = 1, R = 1;
    for(int k = 2; k <= n; k++){
        if(k > R){
            int i = 1, j = k;
            while(j <= n && N[i] == N[j]) i++, j++;
            i--, j--;
            L = k, R = j;
            Z[k] = R - L + 1;
        }
        else{
            int k2 = k - L + 1;
            if(Z[k2] < R - k + 1)
                Z[k] = Z[k2];
            else{
                int i = R - k + 2, j = R + 1;
                while(j <= n && N[i] == N[j]) i++, j++;
                i--, j--;
                L = k, R = j;
                Z[k] = R - L + 1;
            }
        }
        if(k > m && Z[k] >= m)
            st[++last] = k - m - 1;
    }
    n -= m;
}
