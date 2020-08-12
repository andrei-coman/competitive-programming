const long long MOD = 1000000007;
int n;
int ciur[1 + MAXN / 2 + 1];
int phi[1 + MAXN];
int prime[1 + MAXP], ind;

inline void TotientFunction(){
    phi[2] = 1, prime[++ind] = 2;
    for(int i = 2; i <= n; i++){
        if(i % 2){
            if(!ciur[i / 2 + 1]){
                prime[++ind] = i;
                ciur[i / 2 + 1] = i;
                phi[i] = i - 1;
            }

            int j;
            for(j = 1; j <= ind && i * prime[j] <= n && prime[j] < ciur[i / 2 + 1]; j++){
                if(prime[j] != 2) ciur[i * prime[j] / 2 + 1] = prime[j];
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            }
            if(j <= ind && i * prime[j] <= n && prime[j] == ciur[i / 2 + 1]){
                ciur[i * prime[j] / 2 + 1] = prime[j];
                phi[i * prime[j]] = phi[i] * prime[j];
            }
        }
        else if(2 * i <= n)
            phi[i * 2] = phi[i] * 2;
    }
}
