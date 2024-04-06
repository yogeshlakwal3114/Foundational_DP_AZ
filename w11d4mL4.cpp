#include<bits/stdc++.h>
using namespace std;
#define int long long

/*....... 2 Player P1 & P2 plays the game and pick number from Left or right of arr..........*/
/*........ Find the max (P1 - P2)...... so that P1 can win the game........................*/

int n;
int arr[2021];

int dp[2021][2021];
bool done[2021][2021];

int rec(int l, int r){
    // pruning

    // Base case
    if(l==r){
        return arr[l];
    }

    // cache check
    if(done[l][r]){
        return dp[l][r];
    }

    // compute
    int ans = max(arr[l]-rec(l+1,r) , arr[r]-rec(l,r-1));

    done[l][r] = 1;
    return dp[l][r] = ans;  
}


void solve(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            done[i][j] = 0;
        }
    }
    cout<<rec(0,n-1);
}

signed main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);

     solve();
     return 0;
}