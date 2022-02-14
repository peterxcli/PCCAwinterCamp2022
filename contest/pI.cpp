#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);
    string s;
    unsigned long long a, c;
    while (cin >> s) {
        cin >> a;
        string b[a];
        int d[a];
        for (int i = 0; i < a; i++) {
            cin >> b[i];
            c = s.find(b[i], 0);
            while (c > b[i].size()) {
                b[i].erase(0, 1);
                c = s.find(b[i], 0);
            }
            d[i] = b[i].size();
        }
        int e = 0;
        for (int i = 0; i < a; i++) {
            e ^= d[i];
        }
        if (e) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
    }
    return 0;
}