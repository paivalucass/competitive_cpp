#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

pair<vector<long long>, vector<int>> dijkstra(int n, int start, vector<vector<pair<int,int>>> &adj) {
    vector<long long> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);
    dist[start] = 0;

    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    return {dist, parent};
}

vector<int> reconstruct_path(int start, int end, const vector<int> &parent) {
    vector<int> path;
    for (int v = end; v != -1; v = parent[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    if (path.front() != start) return {}; // no path
    return path;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int start = 1, end = n;

    auto [dist, parent] = dijkstra(n, start, adj);
    vector<int> path = reconstruct_path(start, end, parent);

    if (dist[end] == INF) {
        cout << -1;
        return 0;
    }

    for (int v : path)
        cout << v << " ";
}
