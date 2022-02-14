//https://codeforces.com/contest/446/problem/C
#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long
#define MAXN 300005
const int mod = 1e9+9;

void build(int x, int l, int r) {
    if (l == r) {
        seg[x] = a[l];
        return;
    }
    int m = (l+r) >> 1;
    build(2*x+1, l, m), build(2*x+2, m+1, r);
    seg[x] = seg[2*x+1] + seg[2*x+2];
}

void modify(int x, int l, int r, int ql, int qr, int val) {
    if (l == r) {
        
    }
}

int query() {

}

int n, m, seg[4*MAXN+5], tags[4*MAXN+5], a[MAXN];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(0, 1, n);
    return 0;
}