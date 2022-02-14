//https://open.kattis.com/problems/control
#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long
#define MAXN 500005
int sz[MAXN], f[MAXN];

int findf(int x) {
    if (f[x] == x) return x;
    else return f[x] = findf(f[x]);
}

void merge(int a, int b) {
    a = findf(a), b = findf(b);
    if (sz[a] < sz[b]) swap(a, b);
    if (a == b) return;
    f[b] = a;
    sz[a] += sz[b];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < MAXN; i++) f[i] = i, sz[i] = 1;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        vector<int> v(m, 0);
        set<int> parents;
        for (auto &x : v) {
            cin >> x;
            x = findf(x);
            parents.insert(x);
        }
        int tmp = 0;
        for (auto x : parents) {
            tmp += sz[x];
        }
        if (tmp == m) {
            ans++;
            for (int i = 1; i < m; i++) {
                merge(v[0], v[i]);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}