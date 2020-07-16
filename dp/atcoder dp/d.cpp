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
const int N=1e9+7;

// dp[i][j] means we are at position i and total sum in knapsack is j
// so aat position i we can take the element i or leave it
// if we take it the transiotio nto dp[i][j]--->dp[i-1][j-weight[i]] other wise dp[i][j]-->dp[i-1][j]
//iterative approach   time-O(n*W)  space-O(n*W)


//Note at given (i,j) we only need to store the value in previous row i.e (i-1,j)
//so storing info about all the rows is not required
//with this  observation we think we can reduce space
//time-O(n*W) space-O(W)

int main()
{

   
   int n,w;
   cin>>n>>w;
   ll arr[n][2];
   forl(i,0,n)forl(j,0,2)cin>>arr[i][j];

   //O(N*W) space
//    ll dp[n+1][w+1];
   
//    forl(i,0,w+1) dp[0][i]=0;
//    forl(i,0,n+1) dp[i][0]=0;
//    forl(i,1,n+1)
//    {
//        forl(j,0,w+1)
//        {
//            if(j>=arr[i-1][0])dp[i][j]=max(dp[i-1][j],dp[i-1][j-arr[i-1][0]]+arr[i-1][1]);
//            else dp[i][j]=dp[i-1][j];
//        }
//    }
    //cout<<dp[n][w]<<endl;




    //Printing which elements are taken using the above dp

    // vector<int>v;
    // ll wt=w;
    // rfor(i,n,1)
    // {
    //     if(dp[i][wt]==dp[i-1][wt-arr[i-1][0]]+arr[i-1][1]) 
    //     {   
    //      //this means if i have included the last object then value at (i,wt) must be equal to (i-1,wt-weight[i])+val[i]
    //      //else it would e equal to (i-1,wt);
    //         v.pb(1);
    //         wt=wt-arr[i-1][0];

    //     } 
    //     else
    //     {
    //          v.pb(0);
    //     }
    // }
    //print the reversed vecctor
    // rfor(i,v.si-1,0)
    // {
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;

   



    //O(W) space soln

    ll dp[w+1];
    forl(i,0,w+1)dp[i]=0;
    forl(i,0,n)
    {   
        rfor(j,w,0)
        {
            if(j-arr[i][0]>=0) dp[j]=max(dp[j],dp[j-arr[i][0]]+arr[i][1]);
        }
    }
    //Note here we know for dp[j] we need dp[j-weight[i]]
    //so we traverse from back so that j-weight[i] does not get affected before j 
    cout<<dp[w]<<endl;

}
