class Batch{
private:
    static const long long INF = 1e18;
    struct Line{
        long long a, b;
        inline long long get(long long x) {
            return 1LL * a * x + b;
        }
    };
    struct LiChao{
        LiChao *st, *dr;
        Line l;
        LiChao(){
            st = dr = NULL;
            l = {0, INF};
        }
    }*root;

public:
    Batch() {root = new LiChao();}

    inline void fix(LiChao *nod) {
        if(nod -> st == NULL) nod -> st = new LiChao();
        if(nod -> dr == NULL) nod -> dr = new LiChao();
    }

    void add(LiChao *nod, long long left, long long right, Line l) {
        fix(nod);
        Line &curr = nod -> l;
        if(l.get(left) <= curr.get(left) && l.get(right) <= curr.get(right)){curr = l; return;}
        if(l.get(left) >= curr.get(left) && l.get(right) >= curr.get(right)) return;

        long long mid = (left + right) / 2;
        if(curr.get(left) > l.get(left))
            std::swap(l, curr);
        if(curr.get(mid) > l.get(mid)){
            std::swap(l, curr);
            add(nod -> st, left, mid, l);
        }
        else add(nod -> dr, mid + 1, right, l);
    }

    long long query(LiChao *nod, long long left, long long right, long long x) {
        fix(nod);
        long long val = nod -> l.get(x);
        if(left == right) return val;

        long long mid = (left + right) / 2;
        if(x <= mid) return std::min(val, query(nod -> st, left, mid, x));
        return std::min(val, query(nod -> dr, mid + 1, right, x));
    }

    void add(Line l){add(root, 0, 1e9, l);}
    long long query(long long x){return query(root, 0, 1e9, x);}
};
