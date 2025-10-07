#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int n;
    std::vector<long long> tree;

    SegmentTree(int n) : n(n) {
        tree.assign(2 * n, 0); // initialize with 0; change as needed
    }

    // Build from array
    SegmentTree(const std::vector<long long>& a) {
        n = a.size();
        tree.resize(2 * n);
        build(a);
    }

    void build(const std::vector<long long>& a) {
        // insert leaf nodes in tree
        for (int i = 0; i < n; i++) tree[n + i] = a[i];
        // build the tree by calculating parents
        for (int i = n - 1; i > 0; --i)
            tree[i] = tree[i << 1] + tree[i << 1 | 1]; // change op here (e.g. min/max)
    }

    // Update value at position p to val
    void update(int p, long long val) {
        for (tree[p += n] = val; p > 1; p >>= 1)
            tree[p >> 1] = tree[p] + tree[p ^ 1]; // change op here
    }

    // Query on interval [l, r)
    long long query(int l, int r) {
        long long res = 0; // neutral element for sum
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += tree[l++];
            if (r & 1) res += tree[--r];
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int n, q;

    cin >> n >> q;

    vector<long long> values;

    while (n--){
        int v;
        cin >> v;
        values.push_back(v);
    }

    SegmentTree seg(values);

    while (q--){
        int query;
        cin >> query;

        if (query == 1){
            int k, u;
            cin >> k >> u;
            seg.update(k - 1, u);
        }
        else if (query == 2){
            int a, b;
            cin >> a >> b;
            long long res = seg.query(a - 1, b);
            cout << res << "\n";
        }
    }

}
