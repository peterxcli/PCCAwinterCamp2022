#include <bits/stdc++.h>
#define lson rt << 1
#define rson rt << 1 | 1
using namespace std;
#define int long long

const int MXN = 5e5 + 6;
const int INF = 0x3f3f3f3f;
const int mod = 1000000009;
const int p1 = 691504013;
const int p2 = 308495997;
const int p3 = 276601605;

int n, m;
int ar[MXN], pre[MXN], mul1[MXN], mul2[MXN];
int sum[MXN << 2], lazy1[MXN << 2], lazy2[MXN << 2];
int ksm(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) res = res * a % mod;
    }
    return res;
}
void check(int &a) {
    if (a >= mod) a %= mod;
}
void push_up(int rt) {
    sum[rt] = sum[lson] + sum[rson];
    check(sum[rt]);
}
void push_down(int l, int r, int rt) {
    if (lazy1[rt] == 0 && lazy2[rt] == 0) return;
    int a = lazy1[rt], b = lazy2[rt];
    int mid = (l + r) >> 1;
    int len1 = mid - l + 1, len2 = r - mid;
    lazy1[lson] += a;
    lazy2[lson] += b;
    sum[lson] = sum[lson] + a * ((mul1[len1 + 2] - mul1[2]) % mod + mod);
    check(sum[lson]);
    sum[lson] = (sum[lson] - b * ((mul2[len1 + 2] - mul2[2]) % mod + mod)) % mod + mod;
    check(sum[lson]);
    lazy1[rson] += a * mul1[len1] % mod;
    lazy2[rson] += b * mul2[len1] % mod;
    sum[rson] = sum[rson] + a * mul1[len1] % mod * ((mul1[len2 + 2] - mul1[2]) % mod + mod);
    check(sum[rson]);
    sum[rson] = (sum[rson] - b * mul2[len1] % mod * ((mul2[len2 + 2] - mul2[2]) % mod + mod)) % mod + mod;
    check(sum[rson]);
    lazy1[rt] = lazy2[rt] = 0;
    check(lazy1[lson]);
    check(lazy1[rson]);
    check(lazy2[lson]);
    check(lazy2[rson]);
}
void update(int L, int R, int l, int r, int rt, int x, int y) {
    if (L <= l && r <= R) {
        lazy1[rt] += x;
        lazy2[rt] += y;
        check(lazy1[rt]);
        check(lazy2[rt]);
        sum[rt] = sum[rt] + x * ((mul1[r - l + 3] - mul1[2]) % mod + mod);
        check(sum[rt]);
        sum[rt] = (sum[rt] - y * ((mul2[r - l + 3] - mul2[2]) % mod + mod)) % mod + mod;
        check(sum[rt]);
        return;
    }
    push_down(l, r, rt);
    int mid = (l + r) >> 1;
    if (L > mid)
        update(L, R, mid + 1, r, rson, x, y);
    else if (R <= mid)
        update(L, R, l, mid, lson, x, y);
    else {
        update(L, mid, l, mid, lson, x, y);
        update(mid + 1, R, mid + 1, r, rson, mul1[mid - L + 1] * x % mod, mul2[mid - L + 1] * y % mod);
    }
    push_up(rt);
}
int query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        return sum[rt];
    }
    push_down(l, r, rt);
    int mid = (l + r) >> 1;
    if (L > mid)
        return query(L, R, mid + 1, r, rson);
    else if (R <= mid)
        return query(L, R, l, mid, lson);
    else {
        int ans = query(L, mid, l, mid, lson);
        ans += query(mid + 1, R, mid + 1, r, rson);
        check(ans);
        return ans;
    }
}
int32_t main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cin >> n >> m;
    mul1[0] = mul2[0] = 1;
    for (int i = 1; i < 301000; ++i) {
        mul1[i] = mul1[i - 1] * p1;
        mul2[i] = mul2[i - 1] * p2;
        check(mul1[i]);
        check(mul2[i]);
    }
    for (int i = 1; i <= n; ++i)
        cin >> ar[i], pre[i] = (pre[i - 1] + ar[i]) % mod;
    while (m--) {
        int opt, l, r;
        cin >> opt >> l >> r;
        if (opt == 1) {
            update(l, r, 1, n, 1, 1, 1);
        } else {
            cout << ((p3 * query(l, r, 1, n, 1) % mod + pre[r] - pre[l - 1]) % mod + mod) % mod << "\n";
        }
    }
    return 0;
}