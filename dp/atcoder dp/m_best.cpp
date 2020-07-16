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

inline ll modsub(ll n,ll m, ll mod){
    ll diff = ((n-m+mod)%mod+mod)%mod;
    return diff;
}
const ll N=1e9+7;
//reducing time

//note for dp[j] we need continuos values starting from dp[j],dp[j-1],dp[j-2]....dp[j-min(j,arr[i])]
//use prefix sums to calculate it previously and return it in o(1) when required
int main()
{
   int n,k;
   cin>>n>>k;
   int arr[n];
   forl(i,0,n)cin>>arr[i];
   ll dp[k+1];//space-->O(k)
   forl(j,0,k+1)
   {
       if(j>arr[0]) dp[j]=0;
       else dp[j]=1;
   }
   //time-->O(n*k)
   forl(i,1,n)
   {
       int ps[k+1];
       ps[0]=dp[0];
       forl(t,1,k+1) ps[t]=modadd(ps[t-1],dp[t],N);
       rfor(j,k,0)
       {
           ll val=0;
           ll mini=j-min(j,arr[i]);
           if(mini==0)val=modadd(val,ps[j],N);
           else val=modadd(val,modsub(ps[j],ps[j-min(j,arr[i])-1],N),N);
           dp[j]=val;    
       }
   }
   cout<<dp[k]<<endl;
}

