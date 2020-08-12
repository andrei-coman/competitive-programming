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
    int i, step;
    for(step = 1; step < n; step <<= 1);

    for(i = 0; step; step >>= 1)
        if(i + step <= n && value >= aib[i + step]){
            i += step, value -= aib[i];
            if(!value) return i;
        }
    return -1;
}
