#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define si size()
#define bk back()
#define popb pop_back()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define emp empty()
#define beg begin()
#define en end()
#define ump unordered_map
#define forl(i,a,n) for(int i=a;i<n;i++)
#define rfor(i,n,a) for(int i=n;i>=a;i--)
#define fore(i,a,n) for(int i=a;i<=n;i++)
#define len length()
// assumption: number of coins o each type of coin type is infinity

// approach:
// 1)dp[i]= min coins required to make sum equal to i
// 2)iterate over all the coin types and dp[i]=min(dp[i],dp[i-coins[j]]); 

int main()
{
    int n; //number of coins
    int coins[n];
    forl(i,0,n) cin>>coins[i]; //type of coins
    int sum;
    cin>>sum; // sum that we want
    int dp[sum+1];
    for(int i=0;i<sum+1;i++ )dp[i]=INT_MAX;
    dp[0]=0;
    forl(i,1,sum+1)
    {
        forl(j,0,n)
        {
            if(i-coins[j]>=0)dp[i]=min(dp[i],1+dp[i-coins[j]]);
        }
        
    }
    cout<<dp[sum]<<endl;


    
}