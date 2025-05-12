


#include <bits/stdc++.h>

using namespace  std;

int main(){



    int n,m;
    cin>>n>>m;

      vector<vector<int>>adj(n+1);

      vector<int>in(n+1,0);


    for(int i=0;i<m;i++){
         

        int a,b;
      cin>>a>>b;

      adj[a].push_back(b);


      in[b]++;

    }



    vector<int>dp(n+1,0);

 queue<int>q;
    for(int i=0;i<=n;i++){

        if(i!=0){
            if(in[i]==0){

                q.push(i);
        }
        }

    }


    while(!q.empty()){


                  

                  int u = q.front(); q.pop();
                   for (int v : adj[u]) {
            dp[v] = max(dp[v], dp[u] + 1);
            in[v]--;
            if (in[v] == 0) q.push(v);
                   }
    }

 int ans=0;
     
        for(int i=0;i<=n;i++){

            ans=max(ans,dp[i]);
        }

        cout<<ans;
    

}