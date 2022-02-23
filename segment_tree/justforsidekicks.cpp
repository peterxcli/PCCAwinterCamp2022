// https://open.kattis.com/problems/justforsidekicks
#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long
#define MAXN 200010

struct Seg{
    int seg[MAXN<<2], tags[MAXN<<2];
    void push(int x) {
        if (tags[x] == 0) return;
        seg[2*x+1] += tags[x];
        seg[2*x+2] += tags[x];
        tags[2*x+1] += tags[x];
        tags[2*x+2] += tags[x];
        tags[x] = 0;
    }
    void pull(int x) {
        seg[x] = seg[2*x+1] + seg[2*x+2];
    }
    void modify(int x, int l, int r, int ql, int qr, int val) { 
        if (ql <= l && r <= qr) {
            seg[x] += val;
            tags[x] += val;
            return;
        }
        push(x);
        int m = (l+r)>>1;
        if (qr <= m) modify(2*x+1, l, m, ql, qr, val);
        else if (ql >= m+1) modify(2*x+2, m+1, r, ql, qr, val);
        else modify(2*x+1, l, m, ql, qr, val), modify(2*x+2, m+1, r, ql, qr, val);
        pull(x);
    }
    int query(int x, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return seg[x];
        push(x);
        int m = (l+r)>>1;
        if (qr <= m) return query(2*x+1, l, m, ql, qr);
        else if (ql >= m+1) return query(2*x+2, m+1, r, ql, qr);
        else return query(2*x+1, l, m, ql, qr) + query(2*x+2, m+1, r, ql, qr);
    }
}tree[7];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, v[10], a[MAXN];
    cin >> n >> q;
    for (int i = 1; i <= 6; i++) cin >> v[i];
    string tmp;
    cin >> tmp;
    for (int i = 0; i < tmp.size(); i++) tree[tmp[i]-'0'].modify(0, 1, n, i+1, i+1, 1), a[i+1] = tmp[i]-'0';
    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int k, p;
            cin >> k >> p;
            tree[a[k]].modify(0, 1, n, k, k, -1);
            tree[p].modify(0, 1, n, k, k, 1);
            a[k] = p;
        }
        else if (op == 2) {
            int p, _v;
            cin >> p >> _v;
            v[p] = _v;
        }
        else {
            int l, r;
            cin >> l >> r;
            int ans = 0;
            for (int i = 1; i <= 6; i++) {
                ans += v[i] * tree[i].query(0, 1, n, l, r);
            }
            cout << ans << "\n";
        }
    }
    return 0;
}