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

int main()
{
    int n;
    cin>>n;
    ll h[n],arr[n];
    forl(i,0,n)cin>>h[i];
    forl(i,0,n)cin>>arr[i];
    pair<ll,ll> dp[n+1][2]; //h-b
    forl(i,0,n+1) 
    {
        dp[i][0]={0,0};
        dp[i][1]={0,0};
    }
    forl(i,1,n+1)
    {
        if(dp[i-1][1].se>dp[i-1][0].se)
        {
            dp[i][0]=dp[i-1][1];
        }else{
            dp[i][0]=dp[i-1][0];
        }


        if(h[i-1]>dp[i-1][1].fi)
        {
            if(dp[i][1].se<dp[i-1][1].se+arr[i-1])
            {
                dp[i][1].se=arr[i-1]+dp[i-1][1].se;
                dp[i][1].fi=h[i-1];
            }
        }
        if(h[i-1]>dp[i-1][0].fi)
        {
             if(dp[i][1].se<dp[i-1][0].se+arr[i-1])
            {
                dp[i][1].se=arr[i-1]+dp[i-1][0].se;
                dp[i][1].fi=h[i-1];
            }

        }

        if(dp[i][1].se<arr[i-1])
        {
            dp[i][1].fi=h[i-1];
            dp[i][1].se=arr[i-1];
        }
    }

    cout<<max(dp[n][0].se,dp[n][1].se)<<endl;
    
}