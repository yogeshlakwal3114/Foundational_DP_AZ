#include<bits/stdc++.h>
using namespace std;
// #define int long long

int n, m;
int arr[1010][1010];
int dp[1010][1010];
int done[1010][1010];

int rec(int r, int c){
    // Pruning
    if(r<0 || c<0){
        return -1e9;
    }

    // Base Case
    if(r==0 && c==0){
        return arr[0][0];
    }

    // Cache 
    if(done[r][c]){
        return dp[r][c];
    }

    // Compute
    int ans = -1e9;
    if(r!=0){
        ans = max(ans, rec(r-1,c)+arr[r][c]);
    }else if(c!=0){
        ans = max(ans, rec(r,c-1)+arr[r][c]);
    }

    // Save and Return 
    done[r][c] = 1;
    return dp[r][c] = ans;
}

void solve(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            done[i][j] = 0;
        }
    }

    memset(dp, -1, sizeof(dp));
    cout<<rec(n-1, m-1)<<endl;
}

int main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);

     solve();
     return 0;
}