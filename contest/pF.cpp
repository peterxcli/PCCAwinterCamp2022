#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main() {
    int T, t, x;
    bool face_right = true;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> t >> x;
        if (x > t) {
            cout << "impossible" << endl;
            continue;
        } 
        else {
            if (x == t && x == 0) {
                cout << "right" << endl;
                continue;
            } 
            else {
                //if (face_right) {
                if ((t - x) & 1) {
                    face_right = false;
                    cout << "left" << endl;
                } 
                else {
                    face_right = true;
                    cout << "right" << endl;
                }
                //}
                //else {

                //}
            }
        }
    }
    return 0;
}