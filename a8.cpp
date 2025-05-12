

#include <bits/stdc++.h>
using namespace std;

int mod=1e9+7;

 int dp[1001][1001];
int solve( vector<vector<char>>&nums,int i,int j){


    int n=nums.size();
    int m=nums[0].size();

    if(i==n-1 &&  j==m-1){
        return 1;
    }
  
    if(i<0||j<0 ||i>=n||j>=m||nums[i][j]=='#'){
        return 0;
    }

      if(dp[i][j]!=-1){
        return dp[i][j];
    }


     int inc=solve(nums,i+1,j);
     int exc=solve(nums,i,j+1);

     return dp[i][j]= (inc+exc)%mod;
}

int main(){



    int n,m;
    cin>>n>>m;

    vector<vector<char>>nums(n,vector<char>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){


            cin>>nums[i][j];
        }
    }

       memset(dp,-1,sizeof(dp));

    cout<<solve(nums,0,0);
}