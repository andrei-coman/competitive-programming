int n;
struct Point{double x, y;} v[1 + MAXN];
bool cmpXY(Point A, Point B){return (A.x < B.x || (A.x == B.x && A.y < B.y));}
bool cmpTan(Point A, Point B){
    if(A.x == v[1].x && B.x == v[1].x) return A.y < B.y;
    if(A.x == v[1].x) return 1;
    if(B.x == v[1].x) return 0;
    return (A.x - v[1].x) * (B.y - v[1].y) < (B.x - v[1].x) * (A.y - v[1].y);
}
bool convex(int a, int b, int c){
    float S = (v[a].x * v[b].y + v[b].x * v[c].y + v[c].x * v[a].y) -
              (v[a].x * v[c].y + v[b].x * v[a].y + v[c].x * v[b].y);
    return S < 0;
}

int Stack[1 + MAXN], StackSize;
void convexHull(){
    std::sort(v + 1, v + n + 1, cmpXY);
    std::sort(v + 2, v + n + 1, cmpTan);

    Stack[++StackSize] = 1, Stack[++StackSize] = 2;
    for(int i = 3; i <= n; i++){
        while(!convex(Stack[StackSize - 1], Stack[StackSize], i))
            StackSize--;
        Stack[++StackSize] = i;
    }
}
