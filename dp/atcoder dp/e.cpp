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
const int V=1e3;
const ll N=1e18L +5;
const int NUM=1e2;
ll dp[NUM*V+5];


//O(N*TOTAL_VAL)---time
//O(TOTAL_VAL)---space
int main()
{
    int n,w;
    cin>>n>>w;
    ll arr[n][2];
    forl(i,0,n) forl(j,0,2) cin>>arr[i][j];


    // let dp[i] be the min weight to make the the value j
    //initialse all with INF
    forl(i,0,n*V+1) dp[i]=N;
    dp[arr[0][1]]=arr[0][0]; // if i take the first item 
    dp[0]=0; // if i dont take the first item
    forl(i,1,n)
    {
        rfor(j,n*V,0)
        {
            if(j-arr[i][1]>=0)dp[j]=min(dp[j],dp[j-arr[i][1]]+arr[i][0]);
        }
    }
    ll maxval=0;
    forl(i,0,n*V+1) 
    {
        if(dp[i]<=w)maxval=i;
    }
    cout<<maxval<<endl;
   

}
