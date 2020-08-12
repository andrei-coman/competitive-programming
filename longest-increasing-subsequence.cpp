int n;
int v[1 + MAXN];
int d[1 + MAXN], prev[1 + MAXN];
int w[1 + MAXN], num;

inline int src(int val){
    if(num == 0) return 0;
    if(val > v[w[num]]) return num;
    if(val <= v[w[1]]) return 0;

    int st = 1, dr = num;
    while(dr - st > 1){
        int m = (st + dr) / 2;
        if(v[w[m]] >= val) dr = m - 1;
        else st = m;
    }
    if(v[w[dr]] < val) return dr;
    else return st;
}

void print(int ind){
    if(prev[ind] > 0) print(prev[ind]);
    printf("%d ", v[ind]);
}

int max, nmax;
inline void scm(){
    d[1] = 1;
    w[0] = 0;
    w[1] = 1;
    num = 1;

    for(int i = 2; i <= n; i++){
        int pos = src(v[i]);
        prev[i] = w[pos];
        d[i] = pos + 1;
        w[pos + 1] = i;
        if(num < pos + 1) num = pos + 1;
    }

    max = -1, nmax;
    for(int i = 1; i <= n; i++)
        if(d[i] > max){
            max = d[i];
            nmax = i;
        }
    printf("%d\n", max);
    print(nmax);
}
