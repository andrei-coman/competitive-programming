int n;
int left, right;
long long val, ans;

long long aint[4 * MAXN];
long long lazy[4 * MAXN];
void update(int p, int st, int dr){
    if(left <= st && dr <= right){
        lazy[p] += val;
        aint[p] += lazy[p];
        if(st != dr){
            lazy[2 * p] += lazy[p];
            lazy[2 * p + 1] += lazy[p];
        }
        lazy[p] = 0;
    }
    else{
        lazy[2 * p] += lazy[p];
        lazy[2 * p + 1] += lazy[p];
        lazy[p] = 0;

        int m = (st + dr) / 2;
        if(left <= m) update(2 * p, st, m);
        if(m + 1 <= right) update(2 * p + 1, m + 1, dr);

        aint[p] = std::max(aint[2 * p] + lazy[2 * p], aint[2 * p + 1] + lazy[2 * p + 1]);
    }
}

void query(int p, int st, int dr){
    if(left <= st && dr <= right){
        aint[p] += lazy[p];
        if(st != dr){
            lazy[2 * p] += lazy[p];
            lazy[2 * p + 1] += lazy[p];
        }
        lazy[p] = 0;
        ans = std::max(ans, aint[p]);
    }
    else{
        lazy[2 * p] += lazy[p];
        lazy[2 * p + 1] += lazy[p];
        lazy[p] = 0;

        int m = (st + dr) / 2;
        if(left <= m) query(2 * p, st, m);
        if(m + 1 <= right) query(2 * p + 1, m + 1, dr);

        aint[p] = std::max(aint[2 * p] + lazy[2 * p], aint[2 * p + 1] + lazy[2 * p + 1]);
    }
}
