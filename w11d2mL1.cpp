#include<bits/stdc++.h>
using namespace std;
#define int long long

/*.................. No. of ways to reach N in stairs........................*/
/*................. DP added (Optimize).....................*/

int n;
int dp[100100];  // added after

int rec(int level){
    // pruning
     if(level>n){    // out of range
        return 0;
     }

     // Base Case
     if(level == n){   
        return 1;
     }

     if(dp[level] != -1){   // added after
      return dp[level];
     }

     // Compute
     int ans = 0;
     for(int step=1; step<=3; step++){
        if(level+step<=n){
            int ways = rec(level+step);

            ans+=ways;
        }
     }

     dp[level] = ans;   // added after
     //Return
     return ans;
}

void solve(){ 
    cin>>n;
    memset(dp, -1, sizeof(dp));   // added after

    cout<<rec(1);
}

signed main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);

     solve();
     return 0;
}