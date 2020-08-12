const long long MOD = 1000000007;
inline long long logPow(long long a, long long n){
    long long p = 1LL;
    while(n > 0){
        if(n % 2) p = p * a % MOD;
        a = a * a % MOD;
        n /= 2;
    }
    return p;
}
