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
inline ll modadd(ll n,ll m,ll mod){
    ll sum = ((n+m)%mod+mod)%mod;
    return sum;
} 
const ll N=1e9+7;

//dp[i][j] means i-->position j-->total candies taken till now

//transitions

//for each position 
//iterate over all the number of possible candies that can taken at position i i.e t==(0-->arr[i])
//now transition to dp[i-1][k-t] and sum over all to get dp[i][j]
int main()
{
   
    int n,k;
   cin>>n>>k;
   int arr[n];
   forl(i,0,n)cin>>arr[i];
   ll dp[n][k+1];//space--->O(n*k)
   forl(i,0,n) forl(j,0,k+1) dp[i][j]=0; 
   forl(j,0,k+1)
   {
       if(j>arr[0]) dp[0][j]=0;
       else dp[0][j]=1;
   }
   //time-->O(n*k*k)
   forl(i,1,n)
   {
       forl(j,0,k+1)
       {
          forl(t,0,arr[i]+1)
          {
              if(j>=t)dp[i][j]=modadd(dp[i][j],dp[i-1][j-t],N);
          }
       }
   }
   cout<<dp[n-1][k]<<endl;
}


