#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

string K;
int D;
int dp[10005][105][2];  // pos, mod (sum % D), tight

// Digit DP function
int solve(int pos, int mod, bool tight) {
    if (pos == K.size()) return (mod == 0);  // valid if sum % D == 0

    if (dp[pos][mod][tight] != -1) return dp[pos][mod][tight];

    int res = 0;
    int limit = tight ? (K[pos] - '0') : 9;

    for (int digit = 0; digit <= limit; digit++) {
        bool next_tight = tight && (digit == limit);
        res = (res + solve(pos + 1, (mod + digit) % D, next_tight)) % MOD;
    }

    return dp[pos][mod][tight] = res;
}

int main() {
    cin >> K >> D;

    memset(dp, -1, sizeof(dp));

    int ans = solve(0, 0, true);
    ans = (ans - 1 + MOD) % MOD; // remove '0' (not in range [1,K])
    cout << ans << '\n';
}
