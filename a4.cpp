


#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){

    
    int n,w;

    cin>>n>>w;


    vector<int>n1(n),w1(n);

    for(int i=0;i<n;i++){
        cin>>w1[i]>>n1[i];
    }



    vector<vector<ll>>dp(n+1,vector<ll>(w+1,0));

 
          
    for(int i=n-1;i>=0;i--){

        for(int j=1;j<=w;j++){
              

            ll inc=0;
            ll exc=0;

            if(j-w1[i]>=0){
              
                inc=dp[i+1][j-w1[i]]+n1[i];
                
            }

            exc=dp[i+1][j];

            dp[i][j]=max(inc,exc);
        }
    }
    cout<<dp[0][w];

}