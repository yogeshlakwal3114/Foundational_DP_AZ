#include<bits/stdc++.h>
using namespace std;
#define int long long

#define make_pair MP

/*.......... Stone, Paper, Scissor Game ..................... */
/*.......... Find the no. of MAximum Win after k changes.............*/

int n,k;
string s;
int arr[100100];
map<char, int>mp;
map<int, char>rmp;
int dp[1001][3][101];
int back[1001][3][101];

// P=0, H=1, S=2;   
// (0,1), (1,2), (2,0)
int result(int mymove, int compmove){
    return compmove == (mymove+1)%3;     // Important
}

int rec(int level, int last, int ch_left){
    if(ch_left < 0){
        return -1e9;
    }
    if(level == n){
        return 0;
    }
    if(dp[level][last][ch_left] != -1){
        return dp[level][last][ch_left];
    }

    int ans = -1;

    for(int x=0; x<3; x++){
        int temp = result(x, arr[level]) + rec(level+1, x, ch_left-(x==last?0:1));
    
        if(temp > ans){
            ans = temp;
            back[level][last][ch_left] = x;
        }
    }
    return dp[level][last][ch_left] = ans;
}

string final_ans;
void generate(int level, int last, int ch_left){
    if(level == n)return;
    int x = back[level][last][ch_left];
    final_ans += rmp[x];
    generate(level+1, x, ch_left-(x==last?0:1));
}

void solve(){
    cin>>n>>k;
    cin>>s;
    final_ans = "";

    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            for(int x=0; x<=k; x++){
                dp[i][j][x] = -1;
            }
        }
    }

    for(int i=0; i<n; i++){
        arr[i] = mp[s[i]];
    }

    int ans = -1;
    int best = -1;
    for(int i=0; i<3; i++){
        if (ans < result(i, arr[0]) + rec(1, i, k)) {
            ans = result(i, arr[0]) + rec(1, i, k);
            best = i;
        }
    }
    cout<<ans<<endl;
    final_ans += rmp[best];
    generate(1,best,k);
    cout<<final_ans<<endl;
}

signed main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);

     mp['P'] = 0;
     mp['R'] = 1;
     mp['S'] = 2;
     rmp[0] = 'P';
     rmp[1] = 'R';
     rmp[2] = 'S';

     int t;
     cin>>t;
     while(t--){
        solve();
        cout<<endl; 
     }
     return 0;
}