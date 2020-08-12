bool sieve[1 + MAXN];
std::vector <int> prime;

inline void Sieve(){
    sieve[0] = sieve[1] = 1;
    for(int i = 2; i * i <= MAXN; i++)
        if(sieve[i] == 0)
            for(int j = i * i; j <= MAXN; j += i)
                sieve[j] = 1;

    for(int i = 1; i <= MAXN; i++)
        if(!sieve[i])
            prime.push_back(i);
}
