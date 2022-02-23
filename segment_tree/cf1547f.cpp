//https://codeforces.com/problemset/problem/1547/F
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define MAXN 400010
using namespace std;

int seg[MAXN<<2], a[MAXN], all_gcd = 0, n;

void build(int x, int l, int r) {
    if (l == r) {
        seg[x] = a[l];
        return;
    }
    int m = (l+r)/2;
    build(2*x+1, l, m), build(2*x+2, m+1, r);
    seg[x] = __gcd(seg[2*x+1], seg[2*x+2]);
}

int query(int x, int l, int r, int ql, int qr) {
    if (ql <= l && qr >= r) {
        return seg[x];
    }
    int m = (l+r)>>1;
    if (qr <= m) return query(2*x+1, l, m, ql, qr);
    else if (ql >= m+1) return query(2*x+2, m+1, r, ql, qr);
    else return __gcd(query(2*x+1, l, m, ql, qr), query(2*x+2, m+1, r, ql, qr));
}

bool check(int m) {
    for (int i = 0; i < n; i++) {
        int l = i, r = i+m;
        if (query(0, 0, 2*n-1, l, r) != all_gcd) return false; 
    }
    return true;
}

void solve_subtask() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], a[i+n] = a[i];
    build(0, 0, 2*n-1);
    all_gcd = query(0, 0, 2*n-1, 0, 2*n-1);
    int l = 0, r = n;
    while (l < r) {
        int m = (l+r)>>1;
        if (check(m)) r = m;
        else l = m+1;
    }
    cout << l << "\n";
}
int32_t main() {    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt = 1;
#ifdef MANY_SUBTASK
    cin >> cnt;
#endif
    while (cnt--) {
        solve_subtask();
    }
    return 0;
}