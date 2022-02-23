#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long
#define MAXN 200010

int seg[MAXN<<2], tags[MAXN<<2], a[MAXN];
void push(int x, int l, int r) {
    // if (tags[x] == 0 || l == r) return;
    if (tags[x] == 0) return;
    seg[2*x+1] += tags[x];
    seg[2*x+2] += tags[x];
    tags[2*x+1] += tags[x];
    tags[2*x+2] += tags[x];
    tags[x] = 0;
}

void pull(int x, int l, int r) {
    // if (l == r) return;
    seg[x] = min(seg[2*x+1], seg[2*x+2]);
}

void modify(int x, int l, int r, int ql, int qr, int val) {
    if (ql <= l && qr >= r) {
        tags[x] += val;
        seg[x] += val;
        return;
    }
    push(x, l, r);
    int m = (l+r) >> 1;
    if (qr <= m) modify(2*x+1, l, m, ql, qr, val);
    else if (ql >= m+1) modify(2*x+2, m+1, r, ql, qr, val);
    else modify(2*x+1, l, m, ql, qr, val), modify(2*x+2, m+1, r, ql, qr, val);
    pull(x, l, r);
}

int query(int x, int l, int r, int ql, int qr) {
    if (ql <= l && qr >= r) return seg[x];
    push(x, l, r);
    int m = (l+r) >> 1;
    if (qr <= m) return query(2*x+1, l, m, ql, qr);
    else if (ql >= m+1) return query(2*x+2, m+1, r, ql, qr);
    else return min(query(2*x+1, l, m, ql, qr), query(2*x+2, m+1, r, ql, qr));
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        modify(0, 0, n-1, i, i, a[i]);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int l, r, v;
        cin >> l >> r;
        if (cin.peek() != '\n') {
            cin >> v;
            if (l <= r) modify(0, 0, n-1, l, r, v);
            else modify(0, 0, n-1, l, n-1, v), modify(0, 0, n-1, 0, r, v);
        }
        else {
            if (l <= r) cout << query(0, 0, n-1, l, r) << "\n";
            else cout << min(query(0, 0, n-1, l, n-1), query(0, 0, n-1, 0, r)) << "\n";
        }
    }
    return 0;
}