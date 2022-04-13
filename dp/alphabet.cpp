//https://open.kattis.com/problems/alphabet
#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
//#define int long long
int dp[55][55];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str1, str2 = "abcdefghijklmnopqrstuvwxyz";
    while (cin >> str1) {
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < str1.length(); i++) {
            for (int j = 0; j < str2.length(); j++) {
                if (str1[i] == str2[j]) dp[i+1][j+1] = dp[i][j] + 1;
                else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
        cout << 26-dp[str1.length()][str2.length()] << "\n";
    }
    return 0;
}