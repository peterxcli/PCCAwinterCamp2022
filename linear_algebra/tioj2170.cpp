//https://tioj.ck.tp.edu.tw/problems/2170
// #define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int MAXROW = 1005;
const int MAXCOL = 1005;
int mod = 100000007;
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
void GaussianElimination() {
    int pivot = 0;
    for (int i = 0; i < row; i++) {
        if (A[i].col[pivot] == 0) {
            for (int j = i+1; j < row; j++) {
                if (A[j].col[pivot] != 0) {FirstRowOpt(i, j); break;}
            }
        }
        SecondRowOpt(i, inverse(A[i].col[pivot]));
        for (int j = i+1; j < row; j++) ThirdRowOpt(i, j, -A[j].col[pivot]);
        pivot++;
    }
    for (int i = row-1; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            ThirdRowOpt(i, j, -A[j].col[i]);
        }
    }
}
int N;
void solve_subtask() {
    cin >> N >> mod;
    for (int i = 0; i < N; i++) cin >> A[i].col[N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> A[j].col[i];
    }
    row = N, col = N+1;
    GaussianElimination();
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j <= N; j++) cout << A[i].col[j] << " ";
    //     cout << "\n";
    // }
    // cout << "\n";
    for (int i = 0; i < row; i++) cout << (A[i].col[N]+mod)%mod << (i == row-1 ? "\n" : " ");
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