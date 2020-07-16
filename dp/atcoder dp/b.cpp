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

const int MAX=1e5+7;
ll mem[MAX];

//recursive solution
//extend same solution of a to this by simulating for k jumps
ll step(int pos,int k,int n,int arr[])
{
    if(pos==n-1) return 0;
    if(mem[pos]!=-1) return mem[pos];
    ll val=N;
    forl(i,1,k+1)
    {
        if(pos+i<=n-1)val=min(val,step(pos+i,k,n,arr)+abs(arr[pos]-arr[pos+i]));
        else break;
    }
    return mem[pos]=val;
   
}

//dp-- O(n*k)--- n dp states and for each dp state k possiblity
//recursion O(k^n) ---- for every i there are k posiblities


int main()
{
   int n,k;
   cin>>n>>k;
   int arr[n];
   forl(i,0,n) cin>>arr[i];
   memset(mem,-1,sizeof(mem));
   cout<<step(0,k,n,arr)<<endl;

// iterative approach

//    int dp[n];
//    //dp[i] means minimum cost to reach (0..i) from 0
//    forl(i,0,n) dp[i]=N;
//    dp[0]=0;
//    forl(i,1,n)
//    {
//        fore(j,1,k+1)
//        {
//            if(i-j>=0) dp[i]=min(dp[i],dp[i-j]+abs(arr[i]-arr[i-j]));
//        }
//    }
//    cout<<dp[n-1]<<endl;

}
