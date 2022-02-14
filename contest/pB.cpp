#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define MAXN 200010
int f[MAXN], sz[MAXN];

struct disjoint_set{
    void init() {
        for (int i = 0; i < MAXN; i++) f[i] = i, sz[i] = 1;
    }
    bool is_same(int u, int v) {
        return (findf(u) == findf(v));
    }
    void Union(int u, int v){
        u = findf(u), v = findf(v);
        if (sz[u] > sz[v]) swap(u, v);
        sz[u] += sz[v];
        f[v] = u;
    }
    int findf(int x) {
        if (x == f[x]) return x;
        return f[x] = findf(f[x]);
    }
};

struct Edge{
    int u, v;
    int a, b;
    bool operator<(const Edge &rhs) {
        return (b - a) < (rhs.b - rhs.a);
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    disjoint_set dis;
    dis.init();
    cin >> N >> M;
    vector<Edge> edges(M);
    for (int i = 0; i < M; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].a >> edges[i].b;
    }
    sort(edges.begin(), edges.end());
    int ans = 0;
    for (auto edge:edges) {
        if (dis.is_same(edge.u, edge.v)) {
            ans += min(edge.a, edge.b);
            continue;
        }
        ans += edge.b;
        dis.Union(edge.u, edge.v);
    }
    cout << ans << "\n";
    return 0;
}