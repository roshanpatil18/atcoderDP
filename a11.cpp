


#include <bits/stdc++.h>
using namespace std;


int dp[100002];


bool solve( vector<int>&temp,int k){

    if(dp[k+1]!=-1){
        return dp[k+1];
    }


     for(auto it:temp){

        if(k-it>=0 && !solve(temp,k-it)){
            return dp[k+1]=1;
        }
     }
     return dp[k+1]=0;
}
int main(){



    int n,k;
    cin>>n>>k;

    vector<int>temp(n);

    for(int i=0;i<n;i++){
        cin>>temp[i];
    }


    memset(dp,-1,sizeof(dp));

    solve(temp,k);
    if(dp[k+1]==1){
        cout<<"First";
    }else{
        cout<<"Second";
    }

}