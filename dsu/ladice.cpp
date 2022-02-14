//https://open.kattis.com/problems/ladice
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
    used[a] += used[b];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, l;
    cin >> n >> l;
    sz.resize(l+1, 1), f.resize(l+1, 0), used.resize(l+1, 0);
    for (int i = 1; i <= l; i++) f[i] = i;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        merge(a, b);
        a = findf(a), b = findf(b);
        used[a]++;
        if (used[a] <= sz[a]) {
            cout << "LADICA\n";
        }
        else {
            used[a]--;
            cout << "SMECE\n";
        }
    }
    return 0;
}