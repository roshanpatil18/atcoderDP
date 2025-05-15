#include <bits/stdc++.h>
using namespace std;

double solve(int n, vector<vector<vector<double>>>& dp, int i, int j, int k) {
    if (i == 0 && j == 0 && k == 0) return 0;

    if (dp[i][j][k] != -1) return dp[i][j][k];

    int z = n - (i + j + k);
    double res = 1.0;

    if (i > 0) res += (double)i / n * solve(n, dp, i - 1, j + 1, k);
    if (j > 0) res += (double)j / n * solve(n, dp, i, j - 1, k + 1);
    if (k > 0) res += (double)k / n * solve(n, dp, i, j, k - 1);

    res = res / (1.0 - (double)z / n);

    return dp[i][j][k] = res;
}

int main() {
    int n;
    cin >> n;

    vector<int> temp(n);
    int c1 = 0, c2 = 0, c3 = 0;

    for (int i = 0; i < n; i++) {
        cin >> temp[i];
        if (temp[i] == 1) c1++;
        else if (temp[i] == 2) c2++;
        else c3++;
    }

    vector<vector<vector<double>>> dp(n + 1, vector<vector<double>>(n + 1, vector<double>(n + 1, -1)));

    cout << fixed << setprecision(10) << solve(n, dp, c3, c2, c1) << endl;

    return 0;
}
