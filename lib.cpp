#include <bits/stdc++.h>
using namespace std;


// DSU ALGORITHM

 struct DSU {
    std::vector<int> parent, size;
    int num_components;
    int largest = 1;

    DSU(int n) {
        num_components = n;
        parent.resize(n);
        size.assign(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    // Find the representative (root) of the set that contains x
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); // path compression
    }

    // Union two sets containing a and b
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false; // already in the same set
        if (size[a] < size[b]) std::swap(a, b); // union by size
        parent[b] = a;
        size[a] += size[b];
        largest = max(largest, size[a]);
        num_components--;
        return true;
    }

    // Check if two elements are in the same set
    bool same(int a, int b) {
        return find(a) == find(b);
    }

    // Return size of the set containing x
    int set_size(int x) {
        return size[find(x)];
    }

    int set_count(){
        return num_components;
    }

    int set_largest(){
        return largest;
    }
};

// DSU USAGE

int main() {
    DSU dsu(10);
    dsu.unite(1, 2);
    dsu.unite(2, 3);
    if (dsu.same(1, 3))
        std::cout << "1 and 3 are connected\n";
    std::cout << "Set size of 1: " << dsu.set_size(1) << "\n";
}

// Segment Tree (Iterative) – supports range queries and point updates
// Complexity: O(log N) per query or update

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

// SEG TREE USAGE

int main() {
    std::vector<long long> a = {1, 3, 5, 7, 9, 11};
    SegmentTree st(a);

    std::cout << "Sum [1, 5): " << st.query(1, 5) << "\n"; // 3 + 5 + 7 + 9 = 24

    st.update(3, 10); // a[3] = 10
    std::cout << "Sum [1, 5): " << st.query(1, 5) << "\n"; // 3 + 5 + 10 + 9 = 27
}


// Fenwick Tree (Binary Indexed Tree)
// Supports point updates and prefix/range queries
// Complexity: O(log N) per operation

struct Fenwick {
    int n;
    std::vector<long long> bit;

    Fenwick(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    // Build from vector
    Fenwick(const std::vector<long long>& a) : Fenwick(a.size()) {
        for (int i = 0; i < (int)a.size(); i++)
            add(i, a[i]);
    }

    // Add 'val' to element at index 'i' (0-based)
    void add(int i, long long val) {
        for (++i; i <= n; i += i & -i)
            bit[i] += val;
    }

    // Get prefix sum of range [0, i] (0-based)
    long long sum(int i) const {
        long long res = 0;
        for (++i; i > 0; i -= i & -i)
            res += bit[i];
        return res;
    }

    // Get sum on interval [l, r] (inclusive)
    long long range_sum(int l, int r) const {
        return sum(r) - (l ? sum(l - 1) : 0);
    }
};

// FENWICK TREE USAGE

int main() {
    std::vector<long long> a = {1, 2, 3, 4, 5};
    Fenwick ft(a);

    std::cout << "Sum [0, 4]: " << ft.range_sum(0, 4) << "\n"; // 15
    std::cout << "Sum [2, 4]: " << ft.range_sum(2, 4) << "\n"; // 12

    ft.add(2, 5); // a[2] += 5  →  [1,2,8,4,5]
    std::cout << "Sum [0, 4]: " << ft.range_sum(0, 4) << "\n"; // 20
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string text;
    int n;

    // CIN COUT

    cin >> text;
    cout << text;

    // GETLINE
    
    getline(cin, text);

    // VECTOR

    vector<int> v(n , 0);

    // SORT

    sort(v.begin(), v.end());

    // LOWER BOUND UPPER BOUND
    auto it = lower_bound(v.begin(), v.end(), n);
    auto it = upper_bound(v.begin(), v.end(), n);

    // SET (STORE UNIQUE ELEMENTS IN SORTED ORDER) -> USES TREES

    set<int> s;

    // UNORDERED_SET (STORE UNIQUE ELEMENTS IN AN UNORDERED ORDER) -> USES HASHING

    unordered_set<int> us;

    // MAP (STORE DATA AS SORTED PAIRS OR KEYS AND VALUES) -> USES TREES 

    map<int, string> m = {{1, "A"},
              {2, "B"}, {3, "C"}};

    // UNORDERED_MAP (STORE DATA AS PAIRS OF KEYS AND VALUES IN AN UNORDERED ORDER) -> USES HASHING

    unordered_map<int, string> um = {{1, "A"},
              {2, "B"}, {3, "C"}};

    // PRIORITY_QUEUE adds and removes elements according to priority. (ASCENT OR DESCENT) -> USES HEAP

    priority_queue<int> pq;
    priority_queue<int,vector<int>,greater<int>>pq;

    // MULTISET Multiset is an associative container similar to the set, but it can store multiple elements with same value.

    multiset<int> ms1;
    
    multiset<int> ms2 = {5, 3, 3, 1};

    // OUTPUT: 1 3 3 5 



    // DSU

    // Disjoint Set Union (Union-Find) with Path Compression and Union by Size
    // Complexity: O(α(N)) per operation (effectively constant time)
    return 0;
}