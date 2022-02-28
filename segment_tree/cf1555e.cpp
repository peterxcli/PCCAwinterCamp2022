#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long
#define MAXN 1000010
int n, m;
struct segment{
    int l, r;
    int w;
    bool operator<(const segment &rhs) {
        return w < rhs.w;
    }
}segments[MAXN];

int tree[MAXN<<2], tags[MAXN<<2];

void push(int x) {
    if (tags[x] == 0) return;
    tree[2*x+1] += tags[x];
    tree[2*x+2] += tags[x];
    tags[2*x+1] += tags[x];
    tags[2*x+2] += tags[x];
    tags[x] = 0;
}
void pull(int x) {
    tree[x] = min(tree[2*x+1], tree[2*x+2]);
}

void modify(int x, int l, int r, int ql, int qr, int val) {
    if (ql <= l && r <= qr) {
        tags[x] += val;
        tree[x] += val;
        return;
    }
    push(x);
    int m = (l+r) >> 1;
    if (qr <= m) modify(2*x+1, l, m, ql, qr, val);
    else if (ql >= m+1) modify(2*x+2, m+1, r, ql, qr, val);
    else modify(2*x+1, l, m, ql, qr, val), modify(2*x+2, m+1, r, ql, qr, val);
    pull(x);
}

int query(int x, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return tree[x];
    }
    push(x);
    int m = (l+r) >> 1;
    if (qr <= m) return query(2*x+1, l, m, ql, qr);
    else if (ql >= m+1) return query(2*x+2, m+1, r, ql, qr);
    else return min(query(2*x+1, l, m, ql, qr), query(2*x+2, m+1, r, ql, qr));  
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> segments[i].l >> segments[i].r >> segments[i].w, segments[i].r--;
    sort(segments, segments+n);
    int ans = LLONG_MAX;
    for (int i = 0, j = 0; i < n; i++) {
        while (j < n && query(0, 1, m-1, 1, m-1) == 0) {
            modify(0, 1, m-1, segments[j].l, segments[j].r, 1);
            j++;
        }
        if (query(0, 1, m-1, 1, m-1) == 0) break;
        ans = min(ans, segments[j-1].w-segments[i].w);
        modify(0, 1, m-1, segments[i].l, segments[i].r, -1);
    }
    cout << ans << "\n";
    return 0;
}