int aint[4 * MAXN];

int poz, val;
void update(int p, int st, int dr){
    if(st == dr)
        aint[p] = val;
    else{
        int m = (st + dr) / 2;
        if(poz <= m) update(2 * p, st, m);
        else update(2 * p + 1, m + 1, dr);
        aint[p] = std::max(aint[2 * p], aint[2 * p + 1]);
    }
}

int left, right;
int rez;
void query(int p, int st, int dr){
    if(left <= st && dr <= right)
        rez = std::max(rez, aint[p]);
    else{
        int m = (st + dr) / 2;
        if(left <= m) query(2 * p, st, m);
        if(right > m) query(2 * p + 1, m + 1, dr);
    }
}
