// https://toj.tfcis.org/oj/pro/174/
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int MAXROW = 1005;
const int MAXCOL = 1005;
int row, col;
struct row_vec {
    double col[MAXCOL];
};

row_vec A[MAXROW];
void FirstRowOpt(int i, int j) {
    swap(A[i], A[j]);
}
void SecondRowOpt(int i, double k) {
    for (int j = 0; j < MAXCOL; ++j) 
        A[i].col[j] *= k;
}
void ThirdRowOpt(int i, int j, double k) {
    for (int l = 0; l < MAXCOL; ++l)
        A[j].col[l] += k * A[i].col[l];
}
void GaussianElimination() {
    int pivot = -1;
    for (int i = 0; i < row; ++i) { // pick a pivot row
        bool flag = 1;
        while (flag) {
            ++pivot;
            if (pivot == col) 
                break;
            if (A[i].col[pivot]) 
                flag = 0;

            int maxabsi = i;
            for (int j = i + 1; j < row; ++j) {
                if ( fabs(A[j].col[pivot]) > fabs(A[maxabsi].col[pivot]) ) {
                    maxabsi = j;
                    flag = 0;
                }
            }
            FirstRowOpt(i, maxabsi);
        }
        if (A[i].col[pivot] == 0) {
            // cout << i << " " << pivot << "\n";
            if (A[i].col[col-1] == 0) cout << "infinitely many solutions.\n";
            else cout << "no solution.\n";
            return;
        }
        SecondRowOpt(i, 1.0 / A[i].col[pivot]);
        for (int j = i + 1; j < row; ++j) 
            ThirdRowOpt(i, j, -A[j].col[pivot]);
    }

    for (int i = row - 1; i >= 1; --i) {
        for (int j = 0; j < col; ++j) { // find pivot
            if (A[i].col[j]) {
                for (int k = i - 1; k >= 0; --k)
                    ThirdRowOpt(i, k, -A[k].col[j]);
                break;
            }
        }
    }
    if (A[row-1].col[col-2] == 0) {
        if (A[row-1].col[col-1] == 0) cout << "infinitely many solutions.\n";
        else cout << "no solution.\n";
    }
    else cout << "a single unique solution.\n";
}
void solve_subtask() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) cin >> A[i].col[j];
    }
    row = N, col = N+1;
    GaussianElimination();
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j <= N; j++) cout << A[i].col[j] << " ";
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
    while (cnt--) {
        solve_subtask();
    }
    return 0;
}