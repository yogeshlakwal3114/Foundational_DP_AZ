#include<bits/stdc++.h>
using namespace std;
// #define int long long

/*............... Form 5 of DP (Substrate any value of arr to x and find the w/L) ..................*/

int n;
vector<int> moves = {1, 3, 4};

int dp[100100];
int rec(int x){
    if(x==0){
        return 0;
    }

    if(dp[x] != -1){
        return dp[x];
    }

    int ans = 0;
    for(auto v:moves){
        if(v<=x && rec(x-v) == 0){
            ans = 1;
            break;
        }
    }

    return dp[x] = ans;
}

void solve(){
    cin>>n;    

    memset(dp, -1, sizeof(dp));
    cout<<rec(n)<<endl;


    // for(int i=0; i<=20; i++){           // after analysing the data from 0 to 20, we find the pattern 0101111.
    //     cout<<i<<" "<< rec(i)<<endl;
    // }

    // so we found this conclusion
    if(n%7==0 || n%7==2){
        cout<<"Loss"<<endl;
    }else{
        cout<<"Win"<<endl;
    }
}


signed main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);

     solve();
     return 0;
}