void Manacher(char S[], int n, int LPS[]){
    char T[2 * MAXN];
    for(int i = 1; i < n; i++){
        T[2 * i - 1] = S[i];
        T[2 * i] = '*';
    }
    T[2 * n - 1] = S[n];
    n = 2 * n - 1;

    int p = 1;
    for(int i = 1; i <= n; i++){
        LPS[i] = std::max(0, std::min(p + LPS[p] - i, LPS[2 * p - i]));
        while(i - (LPS[i] + 1) >= 1 && i + (LPS[i] + 1) <= n &&
              T[i - (LPS[i] + 1)] == T[i + (LPS[i] + 1)]) LPS[i]++;
        if(i + LPS[i] > p + LPS[p])
            p = i;
    }
}
