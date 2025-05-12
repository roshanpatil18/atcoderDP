


#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){


    int n;
    cin>>n;

    vector<int>a(n),b(n),c(n);

    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }




    vector<vector<ll>>dp(n,vector<ll>(3,0));



    dp[n-1][0]=a[n-1];
    dp[n-1][1]=b[n-1];
    dp[n-1][2]=c[n-1];



    for(int i=n-2;i>=0;i--){
             

        dp[i][0]=max(dp[i+1][1],dp[i+1][2])+a[i];
        dp[i][1]=max(dp[i+1][2],dp[i+1][0])+b[i];
        dp[i][2]=max(dp[i+1][0],dp[i+1][1])+c[i];





             
    }
           
        ll answer=max({dp[0][0],dp[0][1],dp[0][2]});

        cout<<answer;

}