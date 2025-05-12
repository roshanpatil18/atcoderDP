#include <bits/stdc++.h>
using namespace std;

vector<vector<float>> dp;

float solve(vector<float> &nums, int i, int m) {
    int n = nums.size();
    if (i == n) return 1.0;

    if (dp[i][m] != -1.0) return dp[i][m];

    float a = 0.0, b = 0.0;

    if (m > 0) {
        float c = 1.0 - nums[i];
        a = c * solve(nums, i + 1, m - 1);
    }

    b = nums[i] * solve(nums, i + 1, m);

    return dp[i][m] = a + b;
}

int main() {
    int n;
    cin >> n;

    vector<float> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Initialize dp with -1.0
    dp.assign(n + 1, vector<float>(n + 1, -1.0));

    int m = (n / 2) + 1;
    int c = n - m;

    cout << fixed << setprecision(10) << solve(nums, 0, c) << endl;

    return 0;
}
