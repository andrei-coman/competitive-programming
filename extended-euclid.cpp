void cmmdc(long long a, long long b, long long &x, long long &y){
    if(!b) x = 1, y = 0;
    else{
        long long x1, y1;
        cmmdc(b, a % b, x1, y1);
        x = y1;
        y = x1 - y1 * (a / b);
    }
}

long long x, y;
inline bool Euclid(long long a, long long b, long long c){
    long long a1 = a, b1 = b, r;
    while(b1 != 0){
        r = a1 % b1;
        a1 = b1;
        b1 = r;
    }
    if(c % a1 != 0) return 0;
    else{
        cmmdc(a, b, x, y);
        x = x * c / a1;
        y = y * c / a1;
        return 1;
    }
}
