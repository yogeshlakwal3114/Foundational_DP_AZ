#include<bits/stdc++.h>
using namespace std;
// #define int long long

/*................................ Matrix Chain Multiplication...............................*/
/*................... Form 4, L-R DP Problem (Merging the matrix).............................*/

int n;
int x[101], y[101];

int dp[101][101];
int rec(int l, int r){
    // pruning
    if(l>r)return 0;

    // base case
    if(l==r){
        return 0;
    }

    // Cache check
    if(dp[l][r] != -1){
        return dp[l][r];
    }

    // Compute
    int ans = 1e9;
    for(int mid=l; mid<r; mid++){
        ans = min(ans, rec(l, mid) + rec(mid+1, r) + x[l]*y[mid]*y[r]);
    }

    // Save and return
    return dp[l][r] = ans;
}

void solve(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>x[i]>>y[i];
    }

    memset(dp, -1, sizeof(dp));
    cout<<rec(1,n)<<endl;
}

int main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);

     solve();
     return 0;
}