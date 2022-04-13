//https://open.kattis.com/problems/commercials
#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
//#define int long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, p;
    cin >> n >> p;
    int sum = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += (x - p);
        if (sum < 0) sum = 0;
        ans = max(ans, sum);
    }
    cout << ans << "\n";
    return 0;
}