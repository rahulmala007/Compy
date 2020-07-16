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


//dp[l][r] means if any of the player starts the play for the range (l...r)
//what is the maximum value it can gett for that range as both players try to maximize their score-others score
int main()
{
   int n;
   cin>>n;
   ll arr[n];
   forl(i,0,n) cin>>arr[i];
   ll dp[n][n];
   //dp[0][n-1]

   rfor(l,n-1,0)
   {
       forl(r,l,n)
       {
           if(r==l) dp[l][r]=arr[l];
           else {
               dp[l][r]=max(arr[l]-dp[l+1][r],arr[r]-dp[l][r-1]);
           }
       }
   }
   cout<<dp[0][n-1]<<endl;
}

