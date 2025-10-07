#include <bits/stdc++.h>

using namespace std;

struct DSU {
    std::vector<int> parent, size;
    int num_components;
    int num_sets = 0;
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
        num_sets++;
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

int main(){
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);

    int n, m;
    long long result;
    cin >> n >> m;

    DSU sets(n);

    while (m--){
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        sets.unite(x,y);
    }
    result = pow(2, n - sets.set_count());
    cout << result;
}