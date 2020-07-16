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

//dp[i][j] i--->position j-->thing we going to take now 'a' or 'b' or 'c'

// if i am now ar (i,j) i can come here from (i-1,k) such that k!=j
int main()
{
   int n;
   cin>>n;
   int arr[n][3];
   forl(i,0,n)forl(j,0,3) cin>>arr[i][j];

   int dp[n][3];

   forl(i,0,n) forl(j,0,3) dp[i][j]=0;
    forl(i,0,3) dp[0][i]=arr[0][i];

    
    forl(i,1,n)
    {
        forl(j,0,3)
        {
            forl(k,0,3)
            {
                if(k!=j)
                {
                    dp[i][j]=max(dp[i][j],dp[i-1][k]+arr[i][j]);
                }
            }
        }
    }

    cout<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]))<<endl;
}
