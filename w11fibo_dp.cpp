#include<bits/stdc++.h>
using namespace std;
#define ll long long

// Time complexity :- O(n)

const int N = 100100;
int dp[N];

int fibo(int n){
    if(n==0) return 0;
    if(n==1) return 1;

    if(dp[n] != -1){
        // Already computed
        return dp[n];
    }

    // Save the ans
    return dp[n] = fibo(n-1) + fibo(n-2);
}

int main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);

     // Set all value to -1
     memset(dp, -1, sizeof(dp));

     int n=5;
     int ans = fibo(n);
     cout<<ans<<endl;
     return 0;
}