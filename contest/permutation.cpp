#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
    int n;
    std::vector<long long> tree;

    SegmentTree(int n) : n(n) {
        tree.assign(2 * n, 2e18); 
    }

    SegmentTree(const std::vector<long long>& a) {
        n = a.size();
        tree.assign(2 * n, 2e18);
        build(a);
    }

    void build(const std::vector<long long>& a) {
        for (int i = 0; i < n; i++) tree[n + i] = a[i];
        for (int i = n - 1; i > 0; --i)
            tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
    }

    void update(int p, long long val) {
        for (tree[p += n] = val; p > 1; p >>= 1)
            tree[p >> 1] = min(tree[p], tree[p ^ 1]);
    }

    long long query_min(int l, int r) {
        long long res = 2e18;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = min(res, tree[l++]);
            if (r & 1) res = min(res, tree[--r]);
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    SegmentTree seg(a);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int k;
            long long u;
            cin >> k >> u;
            seg.update(k - 1, u); // Convert to 0-based
        } else {
            int l, r;
            cin >> l >> r;
            cout << seg.query_min(l - 1, r) << '\n'; // [l-1, r)
        }
    }
    return 0;
}