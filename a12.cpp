#include <bits/stdc++.h>
using namespace std;

using ll = long long;
vector<ll> a;
ll dp[3005][3005];

ll solve(int i, int j) {
    if (i > j) return 0;
    if (dp[i][j] != LLONG_MIN) return dp[i][j];
    return dp[i][j] = max(a[i] - solve(i + 1, j), a[j] - solve(i, j - 1));
}

int main() {
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            dp[i][j] = LLONG_MIN;

    cout << solve(0, n - 1) << endl;
}
