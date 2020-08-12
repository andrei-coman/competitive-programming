#define zeros(x) (x & (-x))

int n;
int aib[MAXN + 1];
inline void add(int position, int value){
    for(int i = position; i <= n; i += zeros(i))
        aib[i] += value;
}

inline int query(int position){
    int ans = 0;
    for(int i = position; i > 0; i -= zeros(i))
        ans += aib[i];
    return ans;
}

inline int binarySearch(int value){
    int st = 1, dr = n;
    while(dr - st > 1){
        int m = Compute((st + dr) / 2);
        if(m < value) st = (st + dr) / 2 + 1;
        else dr = (st + dr) / 2;
    }
    if(Compute(st) == value) return st;
    if(Compute(dr) == value) return dr;
    return -1;
}
