#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1), ans(n+1);
    ans[1] = -1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i == 1) continue;
        if (a[i] == a[i-1]) ans[i] = ans[i-1];
        else ans[i] = i-1;
    }
    for (int i = 0; i < m; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        if (a[r] != x) cout << r << "\n";
        else if (ans[r] >= l) cout << ans[r] << "\n";
        else cout << "-1\n";
    }
    return 0;
}