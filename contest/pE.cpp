#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
//#define int long long
#define MAXN 200005
pair<int, int> dp[MAXN][2];
int t[MAXN], a[MAXN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> a[i];
    }
    dp[0][0].first = m; dp[0][0].second = 0, dp[0][1].first = m, dp[0][1].second = 0;
    // int k = 0;
    for (int i = 1; i <= n; i++) {
        if (t[i] == 1) {
            if (dp[i-1][0].second < a[i]/10 && dp[i-1][1].second < a[i]/10) {
                return cout << "-1\n", 0;
            }
            else if (dp[i-1][0].second < a[i]/10) {
                dp[i][0].first = dp[i-1][1].first, dp[i][0].second = dp[i-1][1].second - a[i]/10;
                dp[i][1] = dp[i][0];
            }
            else if (dp[i-1][1].second < a[i]/10) {
                dp[i][0].first = dp[i-1][0].first, dp[i][0].second = dp[i-1][0].second - a[i]/10;
                dp[i][1] = dp[i][0];
            }
            else {
                dp[i][0] = dp[i-1][0]; dp[i][0].second -= a[i]/10;
                dp[i][1] = dp[i-1][1]; dp[i][1].second -= a[i]/10;
            }
        }
        else {
            pair<int, int> t[2] = {dp[i-1][0], dp[i-1][1]};
            t[0].first--, t[0].second += (10-a[i]/10);
            t[1].first--, t[1].second += (10-a[i]/10);
            dp[i][0] = max(t[0], t[1]);
            if (dp[i][0].first < 0 || dp[i][0].second < 0) {
                return cout << "-1\n", 0;
            }
            if (dp[i-1][0].second < a[i]/10 && dp[i-1][1].second < a[i]/10) {
                // return cout << "-1\n", 0;
                dp[i][1] = dp[i][0];
            }
            else if (dp[i-1][0].second < a[i]/10) {
                dp[i][1].first = dp[i-1][1].first, dp[i][1].second = dp[i-1][1].second - a[i]/10;
                // dp[i][1] = dp[i][0];
            }
            else if (dp[i-1][1].second < a[i]/10) {
                dp[i][1].first = dp[i-1][0].first, dp[i][1].second = dp[i-1][0].second - a[i]/10;
                // dp[i][1] = dp[i][0];
            }
            else {
                dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
                dp[i][1].second -= a[i]/10;
                // dp[i][1] = dp[i-1][1];
                // dp[i][1].second -= a[i]/10;
            }
            
        }
    }
    cout << max(dp[n][0].first, dp[n][1].first) << "\n";
    return 0;
}