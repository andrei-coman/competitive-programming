int valid[1 + MAXM];
std::vector <std::pair<int, int>> G[1 + MAXN];
std::vector <int> tour;
 
void cycle(int node){
    while(G[node].size()) {
        auto [dest, ind] = G[node][0];
        std::swap(G[node][0], G[node].back());
        G[node].pop_back();
        if(valid[ind]) {
            valid[ind] = 0;
            cycle(dest);
        }
    }
    tour.push_back(node);
}
