long long euler[1 + MAXN];
inline void TotientFunction(){
    for(int i = 1; i <= MAXN; i++)
        euler[i] = i;
    for(int i = 2; i <= MAXN; i++)
        if(euler[i] == i)
            for(int j = i; j <= MAXN; j += i)
                euler[j] = euler[j] * (i - 1) / i;
}
