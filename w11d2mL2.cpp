#include<bits/stdc++.h>
using namespace std;
#define int long long

/*.............. Place n queen in n*n Grid(matrix)................. */

int n;
int queen[20];     // queen[i] --> where is my Queen in row i.

bool check(int row, int col){
    for(int i=0; i<row; i++){
        int prow = i;
        int pcol = queen[i];
        if(pcol == col || abs(row-prow) == abs(col-pcol)){
            return 0;
        }
    }
    return 1;
}

int rec(int level){
    if(level==n){
        return 1;
    }
 
    int ans = 0;
    for(int col=0; col<n; col++){
        if(check(level, col)){
            // place the queen
            queen[level] = col;
            ans += rec(level+1);

            // Revert placing the queen
            queen[level] = -1;
        }
    }
    return ans;
}

void solve(){
    cin>>n;
    memset(queen, -1, sizeof(queen));

    cout<<rec(0)<<endl;
}

signed main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);

     solve();
     return 0;
}