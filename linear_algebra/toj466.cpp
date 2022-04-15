//https://toj.tfcis.org/oj/pro/466/
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int MAXROW = 30;
const int MAXCOL = 30;
const int mod = 100000007;
int row, col;
struct row_vec {
    int col[MAXCOL];
};

row_vec A[MAXROW];
void FirstRowOpt(int i, int j) {
    swap(A[i], A[j]);
}
void SecondRowOpt(int i, int k) {
    for (int j = 0; j < col; ++j) A[i].col[j] *= k, A[i].col[j] = (A[i].col[j] + mod) % mod;
}
void ThirdRowOpt(int i, int j, int k) {
    for (int l = 0; l < col; ++l) A[j].col[l] += k * A[i].col[l], A[j].col[l] = (A[j].col[l] + mod) % mod;
}
int fastp(int a, int power) {
    int ret = 1;
    for (; power; a = a * a % mod, power >>= 1) if (power & 1) ret = ret * a % mod;
    return ret;
}
int inverse(int a) {
    return fastp(a, mod-2);
}
int GaussianElimination() {
    int pivot = -1;
    for (int i = 0; i < row; ++i) {
        ++pivot;
        int maxabsi = i;
        for (int j = i + 1; j < row; ++j) {
            if ( abs(A[j].col[pivot]) > abs(A[maxabsi].col[pivot]) ) {
                maxabsi = j;
            }
        }
        if (!A[i].col[pivot] && i == maxabsi) return 0;
        FirstRowOpt(i, maxabsi);
        if (maxabsi != i) SecondRowOpt(maxabsi, -1);
        for (int j = i + 1; j < row; ++j) if(A[j].col[pivot] != 0) {
            int tmp = (A[i].col[pivot] + mod) % mod;
            SecondRowOpt(i, inverse(tmp));
            ThirdRowOpt(i, j, (-A[j].col[pivot]+mod) % mod);
            SecondRowOpt(i, tmp);
        }
    }
    int ans = 1;
    for (int i = 0; i < row; i++) ans *= (mod+A[i].col[i]) % mod, ans %= mod;
    return ans;
}
int N;
void solve_subtask() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> A[i].col[j];
    }
    row = N, col = N;
    cout << (GaussianElimination() == 0 ? "NO" : "YES") << "\n";
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) cout << A[i].col[j] << " ";
    //     cout << "\n";
    // }
    // cout << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt = 1;
#ifdef MANY_SUBTASK
    cin >> cnt;
#endif
    while (cnt--)
    {
        solve_subtask();
    }
    return 0;
}