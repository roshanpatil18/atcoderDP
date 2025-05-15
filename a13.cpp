#include <bits/stdc++.h>
using namespace std;
using ll = long long;
static const ll MOD = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

 
    vector<vector<ll>> dp(n, vector<ll>(k+1, 0));

  
    for(int s = 0; s <=  a[0]; s++){
        dp[0][s] = 1;
    }

   
    for(int i = 1; i < n; i++){
      
        vector<ll> pref(k+1);
        pref[0] = dp[i-1][0];
        for(int s = 1; s <= k; s++){
            pref[s] = (pref[s-1] + dp[i-1][s]) % MOD;
        }

       
        for(int s = 0; s <= k; s++){
            
            if (s <= a[i]) {
                dp[i][s] = pref[s];
            } else {
                dp[i][s] = (pref[s] - pref[s - a[i] - 1] + MOD) % MOD;
            }
        }
    }

    cout << dp[n-1][k] << "\n";
    return 0;
}
