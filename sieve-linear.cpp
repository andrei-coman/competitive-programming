const long long MOD = 1000000007;
int n;
int ciur[1 + MAXN / 2 + 1];
int prime[1 + MAXP], ind;

inline void LinearSieve(){
    prime[++ind] = 2;
    for(int i = 2; i <= n; i++)
        if(i % 2){
            if(!ciur[i / 2 + 1]){
                prime[++ind] = i;
                ciur[i / 2 + 1] = i;
            }

            for(int j = 1; j <= ind && i * prime[j] <= n && prime[j] <= ciur[i / 2 + 1]; j++)
                if(prime[j] != 2) ciur[i * prime[j] / 2 + 1] = prime[j];
        }
}
