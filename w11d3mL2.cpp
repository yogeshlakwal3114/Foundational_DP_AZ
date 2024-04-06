#include<bits/stdc++.h>
using namespace std;

int n, t;
int x[1001];

int dp[105][10100];

/*......... Find all subsets that sums up to target t ....................*/
/*......... q queries and t target................*/

int rec(int level, int sum_left){
    // pruning
    if(sum_left<0){
        return 0;
    }

    // Base case
    if(level == n+1){
        if(sum_left == 0){
            return 1;
        }else{
            return 0;
        }
    }

    // Cache check
    if(dp[level][sum_left] != -1){
        return dp[level][sum_left];
    }

    // Compute 
    int ans = 0;
    if(rec(level+1, sum_left) == 1){
        ans = 1;
    }else if(rec(level+1, sum_left-x[level])){
        ans = 1;
    }

    // Return 
    return dp[level][sum_left] = ans;
}

void printset(int level, int sum_left){
    // Base Case
    if(level == n+1){
        return;
    }

    // Find the correct transition
    if(rec(level+1, sum_left) == 1){   // Don't take
        printset(level+1, sum_left);
    }
    else if(rec(level+1, sum_left - x[level])){  // Take
        cout<<x[level]<<" ";
        printset(level+1, sum_left - x[level]);
    }
}

void solve(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>x[i];
    }

    memset(dp, -1, sizeof(dp));
    int q; 
    cin>>q;
    while(q--){
        cin>>t;
        if(rec(1,t)){
            printset(1,t);
            cout<<endl;
        }else{
            cout<<"No Solution"<<endl;
        }
    } 
}

int main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);

     solve();
     return 0;
}