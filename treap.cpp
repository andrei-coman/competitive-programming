typedef struct Treap* Tree;
typedef std::pair <Tree, Tree> PTT;
Tree NIL;
struct Treap{
    int val;
    int priority = rand();
    int sub = 1;
    bool lazy = 0;
    Tree st = NIL, dr = NIL;

    Treap(int nval = 0){val = nval;}
    ~Treap(){if(st != NIL) delete st; if(dr != NIL) delete dr;}
};

inline void propagate(Tree T){
    if(T == NIL) return;
    if(T -> lazy){
        std::swap(T -> st, T -> dr);
        T -> st -> lazy ^= 1;
        T -> dr -> lazy ^= 1;
        T -> lazy = 0;
    }
}
inline void reset(Tree T){
    T -> sub = 1 + T -> st -> sub + T -> dr -> sub;
}

int access(Tree T, int pos){
    propagate(T);
    if(T == NIL) return -1;
    if(pos <= T -> st -> sub) return access(T -> st, pos);
    if(pos == T -> st -> sub + 1) return T -> val;
    return access(T -> dr, pos - T -> st -> sub - 1);
}

void order(Tree T){
    propagate(T);
    if(T == NIL) return ;
    order(T -> st);
    printf("%d ", T -> val);
    order(T -> dr);
}

Tree join(Tree A, Tree B){
    if(A == NIL) return B;
    if(B == NIL) return A;
    propagate(A), propagate(B);

    if(A -> priority >= B -> priority){
        A -> dr = join(A -> dr, B);
        reset(A);
        return A;
    }
    else{
        B -> st = join(A, B -> st);
        reset(B);
        return B;
    }
}
PTT split(Tree T, int pos){
    if(T == NIL) return {NIL, NIL};
    propagate(T);

    if(pos <= T -> st -> sub){
        PTT S = split(T -> st, pos);
        T -> st = S.second;
        reset(T);
        return {S.first, T};
    }
    else if(pos == T -> st -> sub + 1){
        PTT S = {T -> st, T};
        T -> st = NIL;
        reset(T);
        return S;
    }
    else{
        PTT S = split(T -> dr, pos - T -> st -> sub - 1);
        T -> dr = S.first;
        reset(T);
        return {T, S.second};
    }
}

inline Tree insert(Tree T, int val, int pos){
    Tree newT = new Treap(val);
    PTT S = split(T, pos);
    return join(S.first, join(newT, S.second));
}
inline Tree erase(Tree T, int st, int dr){
    PTT x = split(T, dr + 1);
    PTT y = split(x.first, st);

    if(y.second != NIL) delete y.second;
    return join(y.first, x.second);
}
inline Tree rotate(Tree T, int st, int dr){
    PTT x = split(T, dr + 1);
    PTT y = split(x.first, st);
    y.second -> lazy ^= 1;
    return join(y.first, join(y.second, x.second));
}

Tree T;
inline void initialize(){
    srand(time(NULL));
    NIL = new Treap();
    NIL -> st = NIL -> dr = NIL;
    NIL -> sub = 0;
    T = NIL;
}
