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

// dp[i] represents if any persomn that starts from i can win or not

// so from dp[i] we can go to dp[i-arr[j]] for all j such that arr[j]<=i
//now to win at position i we must have a loss at position i-arr[j]
//consider all possible scenarios and take or of that
int main()
{
   int n,k;
   cin>>n>>k;
   int arr[n];
   forl(i,0,n)cin>>arr[i];
   bool dp[k+1];
   dp[0]=false;
   forl(i,1,k+1)
   {
       dp[i]=false;
       forl(j,0,n)
       {
           if(arr[j]<=i) dp[i]=(dp[i]||(!dp[i-arr[j]]));
       }
   }
   if(dp[k]) cout<<"First"<<endl;
   else cout<<"Second"<<endl;
    // forl(i,0,k+1) cout<<dp[i]<<" ";
    // cout<<endl; 
}

