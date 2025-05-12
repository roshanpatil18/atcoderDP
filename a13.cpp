


#include <bits/stdc++.h>
using namespace std;

int main(){



    int n,k;

    cin>>n>>k;

  vector<int>temp;

    for(int i=0;i<n;i++){
           
        cin>>temp[i];
    }


    vector<vector<int>>dp(n,vector<int>(k+1,0));

    for(int i=0;i<=temp[i];i++){
        dp[0][i]=1;
    }


      for(int i=1;i<n;i++){
             
            vector<int>pre(k+1,0);

            for(int j=0;j<=k;j++){

                pre[i][j]=
            }


      }

    

    cout<<dp[n-1][k];


}