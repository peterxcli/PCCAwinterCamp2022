//https://open.kattis.com/problems/walrusweights
#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long
int dp[1005][3005];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    // for (int i = 0; i <= 2000; i++) dp[0][i] = 1;
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 3000; j >= 0; j--) {
            if (j - a[i] < 0) continue;
            if (dp[i-1][j-a[i]] || dp[i-1][j]) dp[i][j] = 1;
        }
    }
    int ans = 0, dif = INT32_MAX;
    for (int i = 3000; i >= 0; i--) {
        for (int j = 1; j <= n; j++) {
            if (dp[j][i] && abs(i-1000) < dif) ans = i, dif = abs(i-1000); 
            // cout << ans << " " << dif << "\n";/////////////
        }
    }
    cout << ans << "\n";
    return 0;
}