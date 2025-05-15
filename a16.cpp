#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

vector<vector<ll>> dp;

void dfs(int node, int parent, vector<vector<int>>& adj) {
    ll white = 1;
    ll black = 1;

    for (auto child : adj[node]) {
        if (child == parent) continue;
        dfs(child, node, adj);

        black = (black * dp[child][0]) % mod;
        white = (white * ((dp[child][0] + dp[child][1]) % mod)) % mod;
    }

    dp[node][0] = white;  // node is white
    dp[node][1] = black;  // node is black
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    dp.assign(n, vector<ll>(2, 0));

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;  // convert to 0-based indexing
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, -1, adj);  // root at node 0

    cout << (dp[0][0] + dp[0][1]) % mod << endl;
    return 0;
}
