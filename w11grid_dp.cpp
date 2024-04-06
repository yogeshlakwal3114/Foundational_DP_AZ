#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 1e9;

int n, m;
vector<vector<int>>dp, a;
vector<vector<bool>>visited;

int solve(int r, int c){
    //Base Condition:
    if(r<0 || r>=n || c<0 || c>=m){
        // out of Grid
        return -INF;
    }

    if(r==n-1 && c==m-1){
        return a[n-1][m-1]; 
    }

    if(a[r][c]==0){
        return -INF;
    }

    // Memoization
    if(visited[r][c]){
        return dp[r][c];
    }

    // Compute
    dp[r][c] = a[r][c] + max(solve(r+1, c), solve(r, c+1));
    visited[r][c] = true;

    return dp[r][c];
}

int main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);

     cin>>n>>m;
     a.resize(n, vector<int>(m));
     visited.resize(n, vector<bool>(m, false));

     for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
     }

     cout<<solve(0,0)<<endl;


     return 0;
}