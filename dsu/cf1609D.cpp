//https://codeforces.com/contest/1609/problem/D
#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long
#define MAXN 300000
// int size[MAXN], f[MAXN];

vector<int> sz, f, used;

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
    sz[b] = 0;
    // used[a] += used[b];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, d;
    cin >> n >> d;
    sz.resize(n+1, 1), f.resize(n+1, 0), used.resize(n+1, 0);
    for (int i = 1; i <= n; i++) f[i] = i;
    int tmp = 1;
    for (int i = 1; i <= d; i++) {
        int a, b;
        cin >> a >> b;
        if (findf(a) == findf(b)) tmp++;
        else merge(a, b);
        // a = findf(a), b = findf(b);
        int ans = 0;
        auto v = sz;
        sort(v.rbegin(), v.rend());
        for (int i = 0; i < tmp; i++) {
            ans += v[i];
        } 
        cout << ans-1 << "\n";
    }
    return 0;
}