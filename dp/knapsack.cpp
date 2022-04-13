//https://open.kattis.com/problems/knapsack
#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long

int dp[2005][2005], v[2005], w[2005];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, c;  
    while (cin >> c >> n) {
        memset(dp, 0 , sizeof dp); memset(v, 0, sizeof v); memset(w, 0, sizeof w);
        for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= c; j++) {
                if (j - w[i] < 0) dp[i][j] = dp[i-1][j];
                else dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
                // cout << dp[i][j] << " ";
            }
            // cout << "\n";
        }
        vector<int> ans;
        int j = c;
        for (int i = n; i >= 1; i--) {
            if (dp[i][j] == 0) break;
            if (j - w[i] >= 0 && dp[i][j] != dp[i-1][j]) ans.emplace_back(i-1), j = j - w[i]; 
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (auto x : ans) cout << x << " ";
        cout << "\n";
        ans.clear();
    }
    return 0;
}