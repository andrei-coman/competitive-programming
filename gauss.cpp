int n, m;
const double EPS = 0.0000001;
double a[1 + MAXN][1 + MAXM + 1];
double ans[1 + MAXN];

bool GaussianElimination(){
    int i, j;
    i = j = 1;
    while(i <= n && j <= m){
        int k = i;
        while(k <= n && fabs(a[k][j]) < EPS) k++;
        if(k != n + 1){
            if(k != i) for(int p = 1; p <= m + 1; p++) std::swap(a[i][p], a[k][p]);
            for(int p = j + 1; p <= m + 1; p++) a[i][p] /= a[i][j];
            a[i][j] = 1.0;
            for(int p = i + 1; p <= n; p++){
                for(int q = j + 1; q <= m + 1; q++) a[p][q] -= a[p][j] * a[i][q];
                a[p][j] = 0.0;
            }
            i++;
        }
        j++;
    }

    for(int i = n; i >= 1; i--){
        int j = 1;
        while(j <= m + 1 && fabs(a[i][j] < EPS)) j++;
        if(j == m + 1) return 0;
        else if(j <= m){
            ans[j] = a[i][m + 1];
            for(int k = j + 1; k <= m; k++) ans[j] -= ans[k] * a[i][k];
        }
    }
    return 1;
}
