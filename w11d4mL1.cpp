#include<bits/stdc++.h>
using namespace std;
// #define int long long

/*.............. Longest Increasing subsequence using DP Form-2 .................... */

int n;
int arr[10100];
int dp[10100];

int rec(int level){
    // Best LIS ending at level
    // Pruning
    if(level<0){
        return 0;
    }

    // Base Case

    // Cache Check
    if(dp[level] != -1)return dp[level];

    // Compute
    int ans = 1;
    for(int prev_taken=0; prev_taken<level; prev_taken++){
        if(arr[prev_taken] < arr[level]){
            ans = max(ans, 1+rec(prev_taken));
        }
    }

    // Save and return 
    return dp[level] = ans;
}

void solve(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    memset(dp, -1, sizeof(dp));

    int best = 0;
    for(int i=0; i<n; i++){
        best = max(best, rec(i));
    }
    cout<<best<<endl;
}

int main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);

     solve();
     return 0;
}