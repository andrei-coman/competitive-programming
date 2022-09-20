struct Node {
    long long sum, lazy;
    std::shared_ptr<Node> L, R;
};

void push(std::shared_ptr<Node> node, int left, int right) {
    node->sum += node->lazy * (right - left + 1);
    node->L = std::make_shared<Node>(*node->L);
    node->L->lazy += node->lazy;
    node->R = std::make_shared<Node>(*node->R);
    node->R->lazy += node->lazy;
    node->lazy = 0;
}

std::shared_ptr<Node> add(std::shared_ptr<Node> node,
                          int left, int right,
                          int l, int r, int val) {
    if(l <= left && right <= r) {
        auto newNode = std::make_shared<Node>(*node);
        newNode->lazy += val;
        return newNode;
    }

    int m = (left + right) / 2;
    auto newNode = std::make_shared<Node>(*node);
    if(!newNode->L) newNode->L = std::make_shared<Node>();
    if(!newNode->R) newNode->R = std::make_shared<Node>();
    push(newNode, left, right);

    if(l <= m)
        newNode->L = add(newNode->L, left, m,      l, r, val);
    if(m + 1 <= r)
        newNode->R = add(newNode->R, m + 1, right, l, r, val);
    newNode->sum = newNode->L->sum + newNode->L->lazy * (m - left + 1) +
                   newNode->R->sum + newNode->R->lazy * (right - (m + 1) + 1);
    return newNode;
}

long long sum(std::shared_ptr<Node> node, int left, int right, int l, int r) {
    if(l <= left && right <= r)
        return node->sum + node->lazy * (right - left + 1);

    int m = (left + right) / 2;
    auto newNode = std::make_shared<Node>(*node);
    if(!newNode->L) newNode->L = std::make_shared<Node>();
    if(!newNode->R) newNode->R = std::make_shared<Node>();
    push(newNode, left, right);

    long long ans = 0;
    if(l <= m)
        ans += sum(node->L, left, m, l, r);
    if(m + 1 <= r)
        ans += sum(node->R, m + 1, right, l, r);
    return ans;
}
