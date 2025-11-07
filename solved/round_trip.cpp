#include <bits/stdc++.h>
using namespace std;

vector<int> g[100000 + 1];
int p[100000 + 1];
bool visited[100000 + 1];
int n, m;

void dfs(int u) {
    visited[u] = true;
    for (int v : g[u]) {
        if (v == p[u]){
            continue;
        }

        if (visited[v]) {
            vector<int> path = {v, u};
            int x = p[u];
            while (x != v && x != 0) {
                path.push_back(x);
                x = p[x];
            }
            if (x == v) {
                path.push_back(v);
                cout << path.size() << "\n";
                reverse(path.begin(), path.end());
                for (int c : path) {
                    cout << c << " ";
                }
                cout << "\n";
                exit(0);
            }
        } else {
            p[v] = u;
            dfs(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;

        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)

        if (!visited[i]){
            dfs(i);
        }

    cout << "IMPOSSIBLE" << "\n";
}
