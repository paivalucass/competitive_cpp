#include <bits/stdc++.h> // Not a good thing to do in real conditions (increase compiling time, since it drags all libraries)

using namespace std; 

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

int main(){
    std::ios::sync_with_stdio(false);  // enabled by default
    std::cin.tie(nullptr);            // actually tied to cout by default

    int t;

    cin >> t;

    while (t--){
        int n;

        cin >> n;

        Fenwick tree(2 * n);

        
    }

}