const int n = 2;

void mult(int A[n][n], int B[n][n]){
    int C[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            C[i][j] = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            A[i][j] = C[i][j];
}

void logpow(int Mat[n][n], int e, int Pwr[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            Pwr[i][j] = 0;
        Pwr[i][i] = 1;
    }
    while(e){
        if(e % 2) mult(Pwr, Mat);
        mult(Mat, Mat);
        e /= 2;
    }
}

int linearRecurrence(int Mat[n][n], int Init[n], int e){
    if(e < n) return Init[e];
    e -= (n - 1);
    int Pwr[n][n];
    logpow(Mat, e, Pwr);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            printf("%d ", Pwr[i][j]);
        printf("\n");
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
        ans += Pwr[n - 1][i] * Init[i];
    return ans;
}
