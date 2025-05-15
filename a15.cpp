#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int dp[1 << 21];  // Memoization table

int solve(int n, int mask, vector<vector<int>> &temp) {
    if (mask == (1 << n) - 1)
        return 1;

    if (dp[mask] != -1)
        return dp[mask];

    int ans = 0;
    int man = __builtin_popcount(mask);  // how many men have been paired

    for (int i = 0; i < n; i++) {
        if (!(mask & (1 << i)) && temp[man][i] == 1) {
            ans = (ans + solve(n, mask | (1 << i), temp)) % mod;
        }
    }

    return dp[mask] = ans;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> temp(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> temp[i][j];

    memset(dp, -1, sizeof(dp));
    cout << solve(n, 0, temp) << endl;
    return 0;
}
