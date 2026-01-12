#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, cap, rev;
};

const int INF = 1e9;
vector<vector<Edge>> g;
vector<int> level, ptr;

void add_edge(int a, int b) {
    g[a].push_back({b, 1, (int)g[b].size()});
    g[b].push_back({a, 1, (int)g[a].size() - 1});
}

bool bfs(int s, int t) {
    fill(level.begin(), level.end(), -1);
    queue<int> q;
    q.push(s);
    level[s] = 0;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (auto &e : g[v]) {
            if (e.cap > 0 && level[e.to] == -1) {
                level[e.to] = level[v] + 1;
                q.push(e.to);
            }
        }
    }
    return level[t] != -1;
}

int dfs(int v, int t, int pushed) {
    if (pushed == 0) return 0;
    if (v == t) return pushed;

    for (int &cid = ptr[v]; cid < (int)g[v].size(); cid++) {
        Edge &e = g[v][cid];
        if (e.cap > 0 && level[e.to] == level[v] + 1) {
            int tr = dfs(e.to, t, min(pushed, e.cap));
            if (tr == 0) continue;

            e.cap -= tr;
            g[e.to][e.rev].cap += tr;
            return tr;
        }
    }
    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    while (bfs(s, t)) {
        fill(ptr.begin(), ptr.end(), 0);
        while (int pushed = dfs(s, t, INF))
            flow += pushed;
    }
    return flow;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    g.assign(n + 1, {});
    level.resize(n + 1);
    ptr.resize(n + 1);

    vector<pair<int,int>> edges;
    edges.reserve(m);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
        add_edge(a, b);
        add_edge(b, a);
    }

    int s = 1, t = n;
    int flow = maxflow(s, t);

    vector<int> vis(n + 1, 0);
    queue<int> q;
    q.push(s);
    vis[s] = 1;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto &e : g[u]) {
            if (e.cap > 0 && !vis[e.to]) {
                vis[e.to] = 1;
                q.push(e.to);
            }
        }
    }

    vector<pair<int,int>> answer;

    for (auto &E : edges) {
        int a = E.first, b = E.second;
        if (vis[a] && !vis[b])
            answer.push_back({a, b});
        else if (vis[b] && !vis[a])
            answer.push_back({b, a});
    }

    cout << answer.size() << "\n";
    for (auto &p : answer)
        cout << p.first << " " << p.second << "\n";

    return 0;
}
