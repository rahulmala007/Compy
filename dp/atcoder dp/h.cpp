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
int main()
{
   int n,m;
   cin>>n>>m;
   char arr[n][m];
   forl(i,0,n)forl(j,0,m) cin>>arr[i][j];
   ll dp[n][m];
   forl(i,0,n) forl(j,0,m) dp[i][j]=0;
   dp[0][0]=1;
   forl(i,0,n)
   {
       forl(j,0,m)
       {
           if(arr[i][j]=='#')
           {
               dp[i][j]=0;
               continue;
           }
           if(i-1>=0)dp[i][j]=modadd(dp[i][j],dp[i-1][j],N);
           if(j-1>=0)dp[i][j]=modadd(dp[i][j],dp[i][j-1],N);
 
       }
   }
   cout<<dp[n-1][m-1]<<endl;
}