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
/*
Problem:
A table composed of N x M cells, each having a certain quantity of apples, is given. You start from the upper-left corner. 
At each step you can go down or right one cell. Find the maximum number of apples you can collect.

*/
int main()
{
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    forl(i,0,n) forl(j,0,m) cin>>arr[i][j];
    int dp[n][m];
    forl(i,0,n) forl(j,0,m) dp[i][j]=0;
    dp[0][0]=arr[0][0];
    forl(i,0,n)
    {
        forl(j,0,n)
        {
            if(i==0 && j==0) continue;
            else{
                dp[i][j]=arr[i][j];
                int maxi=0;
                if(i-1>=0) maxi=max(maxi,dp[i-1][j]);
                if(j-1>=0) maxi=max(maxi,dp[i][j-1]);
                dp[i][j]+=maxi;
            }
        }
    }
    cout<<dp[n-1][m-1]<<endl;
}