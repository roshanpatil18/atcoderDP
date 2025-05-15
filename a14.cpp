#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll solve(int i, int j, vector<ll> temp) {
    if (i == j) {
        return temp[i];
    }

    ll ans = 0;
    for (int k = i; k < j; k++) {
        ll a = solve(i, k, temp) + solve(k + 1, j, temp);
        ans = max(ans, a);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<ll> temp(n);
    for (int i = 0; i < n; i++) {
        cin >> temp[i];
    }

    cout << solve(0, n - 1, temp) << endl;
}
