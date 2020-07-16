
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
const ll N=4e18;

//refer array shrinking in basic dps folder for these type of problems
//note: rather than adding dp values we also need how we reach there so to store that value we add the sum of that range(i..j) to dp[i][j]
//at last from dp[0][n-1]  we sutract the sum of the range (0..n-1)
int main()
{
   int n;
   cin>>n;
   ll arr[n];
   forl(i,0,n) cin>>arr[i];
   ll dp[n][n];
   forl(i,0,n) forl(j,0,n) dp[i][j]=N;
   forl(i,0,n)dp[i][i]=arr[i];
   ll ps[n+1];
   ps[0]=0;
   forl(i,1,n+1)ps[i]=ps[i-1]+arr[i-1]; 
   forl(leng,2,n+1)
   {
       fore(i,0,n-leng)
       {
           int j=i+leng-1;
           forl(k,i,j)
           {
               dp[i][j]=min(dp[i][j],ps[j+1]-ps[i]+dp[i][k]+dp[k+1][j]);
           }
           
       }
       
   }
   cout<<dp[0][n-1]-ps[n]<<endl;

}

