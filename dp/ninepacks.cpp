//https://open.kattis.com/problems/ninepacks
#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long
#define MAXN 1000005
const int inf = 2<<29;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int H, B;
    cin >> H;
    vector<int> h(MAXN, inf), b(MAXN, inf);
    h[0] = 0, b[0] = 0;
    for (int i = 0; i < H; i++) {
        int tmp;cin >> tmp;
        for (int j = MAXN-1-tmp; j >= 0; j--) {
            h[j+tmp] = min(h[j+tmp], h[j]+1);
        }
    }
    cin >> B;
    for (int i = 0; i < B; i++) {
        int tmp; cin >> tmp;
        for (int j = MAXN-1-tmp; j >= 0; j--) {
            b[j+tmp] = min(b[j+tmp], b[j]+1);
        }
    }
    int ans = INT32_MAX;
    // for (int i = 1; i < 40; i++) cout << h[i] << " ";cout << "\n";
    // for (int i = 0; i < 40; i++) cout << b[i] << " ";cout << "\n";
    for (int i = 1; i < MAXN; i++) ans = min(ans, h[i]+b[i]);
    if (ans >= inf) cout << "impossible\n";
    else cout << ans << "\n";
    return 0;
}