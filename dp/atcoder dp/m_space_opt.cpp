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

// to optimise space note that only the previous row is needed for the transition i.e for (i,j) we need only (i-1,j-t)
//where t ===(0,arr[i])

//so remove the position state and iterate the dp backwards
//so if we are at dp[j]---> then dp[0],dp[1],dp[2]....dp[k] are unchanged from the previous row and stores the info of previous row
//so iterrate similarly like brute force and get the ans
int main()
{
   int n,k;
   cin>>n>>k;
   int arr[n];
   forl(i,0,n)cin>>arr[i];
   ll dp[k+1];//space--->O(k)
   forl(j,0,k+1)
   {
       if(j>arr[0]) dp[j]=0;
       else dp[j]=1;
   }
   //time---->O(n*k^2)
   forl(i,1,n)
   {
       
       rfor(j,k,0)
       {
           ll val=0;
          forl(t,0,arr[i]+1)
          {
              if(j>=t)val=modadd(val,dp[j-t],N);
          }
          dp[j]=val;
       }
   }
   cout<<dp[k]<<endl;
}


