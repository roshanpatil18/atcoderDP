#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    ll w;
    cin >> n >> w;

    vector<int> val(n), wt(n);
    ll total = 0;

    for (int i = 0; i < n; i++) {
        cin >> wt[i] >> val[i];
        total += val[i];
    }

    vector<ll> dp(total + 1, LLONG_MAX);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (ll t = total; t >= val[i]; t--) {
            if (dp[t - val[i]] != LLONG_MAX) {
                dp[t] = min(dp[t], dp[t - val[i]] + wt[i]);
            }
        }
    }

    ll ans = 0;
    for (ll i = 0; i <= total; i++) {
        if (dp[i] <= w) {
            ans = max(ans, i);
        }
    }

    cout << ans << endl;
    return 0;
}
