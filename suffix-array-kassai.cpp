const int MAXN = 100000;

struct Suffix{
    int value[2];
    int index, newCode;
    bool operator < (const Suffix &aux) const{
        if(value[0] != aux.value[0]) return value[0] < aux.value[0];
        return value[1] < aux.value[1];
    }
};
Suffix S[1 + MAXN];

inline void radixSort(Suffix *Array, Suffix *endArray){
    int dim = endArray - Array;
    int cnt[1 + dim];
    Suffix tmp[dim];
    Suffix *output = tmp;
    for(int d = 1; d >= 0; d--){
        for(int i = 0; i <= dim; i++) cnt[i] = 0;
        for(int i = 0; i <  dim; i++) cnt[Array[i].value[d]]++;
        for(int i = 1; i <= dim; i++) cnt[i] += cnt[i - 1];
        for(int i = dim - 1; i >= 0; i--) output[--cnt[Array[i].value[d]]] = Array[i];
        std::swap(Array, output);
    }
}

void suffixArrays(char* S, int dim, int* suffixes, int* lcp){
    Suffix suff[dim];
    for(int i = 0; i < dim; i++)
        suff[i] = Suffix{{(int)S[i], 0}, i, 0};
    std::sort(suff, suff + dim);

    int inv[dim];
    for(int i = 0; i < dim; i++)
        inv[suff[i].index] = i;

    for(int j = 2; j / 2 <= dim; j <<= 1){
        suff[0].newCode = 1;
        for(int i = 1; i < dim; i++){
            suff[i].newCode = suff[i - 1].newCode;
            if (!(suff[i - 1].value[0] == suff[i].value[0]
                    && suff[i - 1].value[1] == suff[i].value[1]))
                suff[i].newCode++;
        }
        for(int i = 0; i < dim; i++){
            suff[i].value[0] = suff[i].newCode;
            if(suff[i].index + j / 2 < dim)
                suff[i].value[1] = suff[inv[suff[i].index + j / 2]].newCode;
            else
                suff[i].value[1] = 0;
        }
        radixSort(suff, suff + dim);
        for(int i = 0; i < dim; i++)
            inv[suff[i].index] = i;
    }

    for(int i = 0; i < dim; i++){
        suffixes[i] = suff[i].index;
        inv[suff[i].index] = i;
    }

    int prev = 0;
    for(int i = 0; i < dim; i++){
        if(inv[i] != dim - 1){
            int p = suffixes[inv[i]    ];
            int q = suffixes[inv[i] + 1];
            while(p + prev < dim && q + prev < dim && S[p + prev] == S[q + prev])
                prev++;
            lcp[inv[i]] = prev;

            prev -= (prev > 0);
        }
    }
}
