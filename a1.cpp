#include <bits/stdc++.h>
using namespace std;

using ll=long long;
int main(){


    int n;
    cin>>n;

    vector<int>temp(n);

    for(int i=0;i<n;i++){
        cin>>temp[i];
    }
       

    vector<ll>dp(n+1,0);

     dp[n]=0;
     dp[n-1]=0;

    for(int i=n-2;i>=0;i--){
           
        ll jump1 = dp[i + 1] + abs(temp[i] - temp[i + 1]);
        ll jump2 = dp[i + 2] + abs(temp[i] - temp[i + 2]);
        dp[i] = min(jump1, jump2);

        



        

        }

           

        cout<<dp[0];



}