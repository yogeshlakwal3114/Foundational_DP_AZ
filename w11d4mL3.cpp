#include<bits/stdc++.h>
using namespace std;
// #define int long long

/*................. Longest Common Subsequence of String a & b & c...................*/

int n, m, x;
string a, b, c;
int dp[101][101][101];

int rec(int i, int j, int k){
    // Return the LCS of a[i....n-1] and b[j......m-1]
    // Pruning

    // Base Case
    if(i>=n || j>=m || k>=x){
        return 0;
    }

    // Cache
    if(dp[i][j][k] != -1){
        return dp[i][j][k];
    }

    // Compute
    int ans = 0;
    ans = max(ans, rec(i+1, j, k));
    ans = max(ans, rec(i, j+1, k));
    ans = max(ans, rec(i, j, k+1));
    if(a[i] == b[j] && b[j] == c[k]){
        ans = max(ans, 1 + rec(i+1, j+1, k+1));
    }

    // Save and Return 
    return dp[i][j][k] = ans;  
}

void solve(){
    cin>>n>>m>>x;
    cin>>a>>b>>c;

    memset(dp, -1, sizeof(dp));
    cout<<rec(0,0,0)<<endl;
}

int main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);

     solve();
     return 0;
}



/*
#include<bits/stdc++.h>
using namespace std;
// #define int long long

// ................. Longest Common Subsequence of String a & b ...................

int n, m;
string a, b;
int dp[1010][1010];

int rec(int i, int j){
    // Return the LCS of a[i....n-1] and b[j......m-1]
    // Pruning

    // Base Case
    if(i>=n || j>=m){
        return 0;
    }

    // Cache
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    // Compute
    int ans = 0;
    ans = max(ans, rec(i+1, j));
    ans = max(ans, rec(i, j+1));
    if(a[i] == b[j]){
        ans = max(ans, 1 + rec(i+1, j+1));
    }

    // Save and Return 
    return dp[i][j] = ans;  
}

void solve(){
    cin>>n>>m;
    cin>>a>>b;

    memset(dp, -1, sizeof(dp));
    cout<<rec(0,0)<<endl;
}

int main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);

     solve();
     return 0;
}
*/