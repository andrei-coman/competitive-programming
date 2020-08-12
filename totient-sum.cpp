#define MAXVAL 1000000
int phi[1 + MAXVAL];
long long Sum[1 + MAXVAL];

std::unordered_map <int, long long> M;
long long A(int n){
    if(n <= MAXVAL)
        return Sum[n];
    if(!M[n]){
        long long sum = 1LL * n * (n + 3) / 2;
        int k = 2;
        while(k <= n){
            int nval = n / k;
            int last = n / nval;
            sum -= A(nval) * (last - k + 1);
            k = last + 1;
        }
        M[n] = sum;
    }
    return M[n];
}

inline long long TotientFunctionSum(int n){
    phi[1] = 1;
    for(int i = 1; i <= MAXVAL; i++)
        phi[i] = i;

    Sum[1] = 2;
    for(int i = 2; i <= MAXVAL; i++){
        if(phi[i] == i)
            for(int j = i; j <= MAXVAL; j += i)
                phi[j] = phi[j] / i, phi[j] *= (i - 1);
        Sum[i] = phi[i] + Sum[i - 1];
    }

    return A(n) - 1;
}
