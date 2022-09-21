typedef struct Treap* Tree;
typedef std::pair <Tree, Tree> PTT;
Tree NIL;
struct Treap{
    int key, idx;
    int lazyS = 0;
    int priority = rand();
    Tree L = NIL, R = NIL;
 
    Treap(int _key = 0, int _idx = 0) : key(_key), idx(_idx){};
    ~Treap(){ if(L != NIL) delete L; if(R != NIL) delete R; }
};
 
inline void propagate(Tree T){
    if(T == NIL) return;
    T -> key -= T -> lazyS;
    if(T -> L != NIL)
        T -> L -> lazyS += T -> lazyS;
    if(T -> R != NIL)
        T -> R -> lazyS += T -> lazyS;
    T -> lazyS = 0;
}
 
inline void reset(Tree T){
    /* */
}
 
PTT split(Tree T, int val){
    if(T == NIL) return {NIL, NIL};
    propagate(T);
    if(val > T -> key) {
        PTT S = split(T -> R, val);
        T -> R = S.first;
        reset(T);
        return {T, S.second};
    }
    else {
        PTT S = split(T -> L, val);
        T -> L = S.second;
        reset(T);
        return {S.first, T};
    }
}
 
Tree join(Tree A, Tree B){
    if(A == NIL) return B;
    if(B == NIL) return A;
    propagate(A), propagate(B);
    if(A -> priority < B -> priority)
        std::swap(A, B);
 
    PTT S = split(B, A -> key + rand() % 2);
    A -> L = join(A -> L, S.first);
    A -> R = join(A -> R, S.second);
    reset(A);
 
    return A;
}
 
inline Tree insert(Tree T, int val, int idx){
    Tree newT = new Treap(val, idx);
    PTT S = split(T, val);
    return join(S.first, join(newT, S.second));
}
 
inline Tree process(Tree T, int c) {
    PTT S = split(T, c);
    S.second -> lazyS += c;
    return join(S.first, S.second);
}
