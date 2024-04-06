#include<bits/stdc++.h>
using namespace std;
//#define int long long

/*...............Find Max Skill gain you can get when you have x time & k item to select....................*/

int n;
int x,k;
int t[1001];  // time array
int s[1001];  // Skill array

/*.................. DP Code.................*/
int dp[101][101][101];

int rec(int level, int time_taken, int item_taken){
    // Max skill I can make from [level.. n-1]

    // pruning

    //Base Case
    if(level==n){
        return 0;
    }

    // Cache Check
    if(dp[level][time_taken][item_taken]!=-1){
        return dp[level][time_taken][item_taken];
    }

    // Compute
    int ans = dp(level+1, time_taken, item_taken); // Don't Take

    if(time_taken + t[level] <= x && item_taken + 1 <= k){   // Take
        ans = max(ans, s[level] + rec(level+1, time_taken+t[level], item_taken+1)); 
    }

    // Return 
    return dp[level][time_taken][item_taken] = ans;
}


/*................... Recursion code....................*/
/*
int taken[1001];

bool check(int level){
    int timetaken = 0;
    int itemtaken = 0;
    for(int i=0; i<level; i++){
        if(taken[i]){
            timetaken += t[i];
            itemtaken += 1;
        }
    }
    timetaken += t[level];
    itemtaken++;

    if(timetaken<=x && itemtaken<=k){
        return 1;
    }else{
        return 0;
    }
}

int rec(int level){    // Max skill i can make frome [level.....n-1] ... if [0....level-1] decided.
    // Base Case
    if(level == n){
        return 0;
    }

    // Choice 1: Don't take
    int ans = rec(level+1);

    // Choice 2: Take 
    if(check(level)){
        taken[level] = 1;
        // Move
        ans = max(ans, s[level] + rec(level+1));    // Max in [level+1 .... n-1]

        // Revert
        taken[level] = 0;
    }

    return ans;
}
*/

void solve(){
    cin>>n;
    cin>>x>>k;

    for(int i=0; i<n; i++){
        cin>>t[i]>>s[i];
    }

    memset(dp, -1, sizeof(dp)); // For DP
    cout<<rec(0, 0, 0)<<endl;
}

signed main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);

     solve();
     return 0;
}