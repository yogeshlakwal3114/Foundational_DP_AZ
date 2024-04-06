#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*........................DP : Form 1...........................*/

vector<int>a;
vector<vector<int>>dp;

int solve(int i, int S){
    // Base condition
    if(i == -1){
        // Outside the array
        if(S==0)return 1;
        return 0;
    }

    if(S<0){
        // It is not possible to get the negative sum
        return 0;
    }

    // Memoization
     if(dp[i][S] != -1){
        return dp[i][S];
     }
    
    // Compute
    dp[i][S] = (solve(i-1, S-a[i]) || solve(i-1, S));
    return dp[i][S];
}

int main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);
      
     int n, T;
     cin>>n>>T;

     a.resize(n);
     // a[i] is always >= 0
     for(int i=0; i<n; i++){
        cin>>a[i];
     }
     
     // n x T matrix
     // -1 -> not computed
     // 0 -> There doesn't exist a subset of sum s;
     // 1 -> There exist a subset
     dp.resize(n, vector<int>(T+1, -1));

     if(solve(n-1, T)==1){
        cout<<"YES\n";
     }else{
        cout<<"NO\n";
     }
}