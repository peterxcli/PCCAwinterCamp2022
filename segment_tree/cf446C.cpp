// https://codeforces.com/contest/446/problem/C
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAXN 300010

const int mod = 1000000009;

int base1, base2, inv, n, m;
int seq[MAXN];
int quick_pow(int a, int b) {
    int ret = 1;
    for (;b; b>>1, a = a * a % mod) {
        if (b & 1) ret = ret * a % mod;
    }
    return ret;
}
struct Segment_Tree {
#define mid (l + r >> 1)
#define ls x << 1, l, mid
#define rs x << 1 | 1, mid + 1, r
    int p[MAXN], tree[MAXN << 2], lazy[MAXN << 2], q, Inv;
    void init() {
        p[0] = 1;
        for (int i = 1; i <= n; ++i)
            p[i] = p[i - 1] * q % mod;
        Inv = quick_pow(q - 1, mod - 2);
        build(1, 1, n);
        return;
    }
    void push_up(int x) {
        tree[x] = (tree[x << 1] + tree[x << 1 | 1]) % mod;
    }
    void build(int x, int l, int r) {
        if (l == r)
            return;
        build(ls);
        build(rs);
        push_up(x);
        return;
    }
    void add(int x, int l, int r, int a) {
        lazy[x] += a;
        tree[x] += (a * p[r - l + 1] % mod - a + mod) % mod * Inv % mod;
        return;
    }
    void push_down(int x, int l, int r) {
        if (!lazy[x]) return;
        add(ls, lazy[x]);
        add(rs, lazy[x] * p[r - l + 1] % mod);
        lazy[x] = 0;
    }
    void modify(int x, int l, int r, int L, int R, int a) {
        if (l == L && r == R) {
            add(x, l, r, a);
            return;
        }
        push_down(x, l, r);
        if (r <= mid) modify(ls, L, R, a);
        else if (l > mid) modify(rs, L, R, a);
        else {
            modify(ls, L, mid, a);
            modify(rs, mid + 1, R, a * p[mid - L + 1] % mod);
        }
        push_up(x);
        return;
    }
    int query(int x, int l, int r, int L, int R) {
        if (l == L && r == R) return tree[x];
        push_down(x, l, r);
        if (r <= mid) return query(ls, L, R);
        else if (l > mid) return query(rs, L, R);
        else return (query(ls, L, mid) + query(rs, mid + 1, R)) % mod;
    }

}t1, t2;

int32_t main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    t1.q = (383008016 + 1) * quick_pow(2ll, mod - 2) % mod;
    t2.q = (1 - 383008016 + mod) * quick_pow(2ll, mod - 2) % mod;
    inv = quick_pow(383008016, mod - 2);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        seq[i] = (seq[i - 1] + x) % mod;
    }
    t1.init(), t2.init();
    while (m--) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1) {
            t1.modify(1, 1, n, l, r, t1.q);
            t2.modify(1, 1, n, l, r, t2.q);
        } 
        else {
            int a = t1.query(1, 1, n, l, r);
            int b = t2.query(1, 1, n, l, r);
            int ans = (a - b + mod) % mod * inv % mod;
            cout << ((seq[r] - seq[l - 1] + mod) % mod + ans) % mod << "\n";
        }
    }
}