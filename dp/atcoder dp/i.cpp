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


//dp[i][j] represents at ith postition and j number of heads

//initially dp[0][0]=1 as prob. of having 0 heads initially is 1 and dp[0][i] for all i is 0;

// now from dp[i][j]
// if at jth position head comes then probablity is  ==== dp[i][j]-->arr[i]*dp[i-1][j-1]
// if at jth position tail comes then probablity is  ==== dp[i][j]-->(1-arr[i])*dp[i-1][j]

// at last position i.e n total heads must be greater than tails 
//so iterate from j==n/2+1 to n and sum all the probablities
int main()
{
   int n;
   cin>>n;
   long double arr[n+1];
   forl(i,1,n+1) cin>>arr[i];
   long double dp[n+1][n+1];
//    forl(i,0,n+1)forl(j,0,n+1) dp[i][j]=0;
    dp[0][0]=1;
   forl(j,1,n+1) 
   {
       dp[0][j]=0;
   } 

   forl(i,1,n+1)
   {
       forl(j,0,n+1)
       {

            if(j<=i) //this condtion as at ith position max number of heads can be i
            {
                if(j-1>=0)dp[i][j]=arr[i]*dp[i-1][j-1]+(1-arr[i])*dp[i-1][j]; 
            else dp[i][j]=(1-arr[i])*dp[i-1][j];  
            }
            else dp[i][j]=0;
       }
   }
    long double  sum=0;
   forl(i,n/2+1,n+1) sum+=dp[n][i];
   cout<<setprecision(10)<<fixed<<sum<<endl;

}

