


#include <bits/stdc++.h>
using namespace std;
 

using ll=long long;
int main(){


    int n,k;
    cin>>n>>k;


    vector<int>temp(n);

    for(int i=0;i<n;i++){
        cin>>temp[i];
    }

    vector<ll>dp(n,LLONG_MAX);

 
    dp[n-1]=0;

    for(int i=n-2;i>=0;i--){

        for(int j=1;j<=k;j++){
           
           ll jump=LLONG_MAX;
            if(i+j<n){

               jump=dp[i+j]+abs(temp[i]-temp[i+j]);

                 dp[i]=min(dp[i],jump);
            }
              
          
        }
    }
    cout<<dp[0];
}
