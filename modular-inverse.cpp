void gcd(long long &x, long long &y, int a, int b){
    if(!b) x = 1, y = 0;
    else{
        gcd(x, y, b, a % b);
        long long aux = x;
        x = y;
        y = aux - y * (a / b);
    }
}

inline long long modularInverse(int a, int n){
    long long x, y;
    gcd(x, y, a, n);
    return x < 0 ? n + (x % n) : x;
}
