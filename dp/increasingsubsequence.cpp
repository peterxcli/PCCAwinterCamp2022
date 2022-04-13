#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
//#define int long long
int n;
vector<int> a;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> n) {
        a.resize(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
    }
    return 0;
}