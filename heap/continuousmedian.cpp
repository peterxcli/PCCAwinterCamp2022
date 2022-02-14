//https://open.kattis.com/problems/continuousmedian
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve_subtask() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (auto &x : a) cin >> x;
    priority_queue<int, vector<int>, greater<int> > upper;
    priority_queue<int, vector<int>, less<int> > lower;
    if (N == 1) {
        cout << a[0] << "\n";
        return;
    }
    int ans = a[0] + (a[0]+a[1])/2;
    // int m = a[0];
    lower.push(min(a[0], a[1]));
    upper.push(max(a[0], a[1]));
    for (int i = 2; i < N; i++) {
        if (a[i] > upper.top()) upper.push(a[i]);
        else lower.push(a[i]);

        if (abs((int)(upper.size()-lower.size())) == 2) {
            if (upper.size() > lower.size()) {
                lower.push(upper.top());
                upper.pop();
            }
            else {
                upper.push(lower.top());
                lower.pop();
            }
        }
        if (abs((int)(upper.size()-lower.size())) == 1) ans += (upper.size() > lower.size() ? upper.top() : lower.top());
        else ans += (lower.top()+upper.top()) / 2;
    }
    cout << ans << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt = 1;
#ifdef MANY_SUBTASK
    cin >> cnt;
#endif
    while (cnt--) {
        solve_subtask();
    }
    return 0;
}