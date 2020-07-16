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
int mem[MAX];

//recursive solution
//step gives the min value required to go from pos to n-1
int step(int pos,int n,int arr[])
{
    if(pos==n-1) return 0;

    if(mem[pos]!=-1) return mem[pos];
    if(pos==n-2) return (step(pos+1,n,arr)+abs(arr[pos]-arr[pos+1])); 
    else{
        return mem[pos]=min(step(pos+1,n,arr)+abs(arr[pos]-arr[pos+1]),step(pos+2,n,arr)+abs(arr[pos+2]-arr[pos]));
    }
    // cost of jump from pos to pos+1,pos+2 is abs(arr[pos]-arr[pos+1]) or abs(arr[pos]-arr[pos+2])
    // now from there run the step function to find the minimum cost to reach n-1
}

//dp-- O(n)--- n dp states and for each dp state 2 possiblity
//recursion O(2^n) ---- for every i there are two posiblities
int main()
{
   int n;
   cin>>n;
   int arr[n];
   forl(i,0,n) cin>>arr[i];
   memset(mem,-1,sizeof(mem));
   cout<<step(0,n,arr)<<endl;;

// iterative approach

//    int dp[n];
//    //dp[i] means minimum cost to reach (0..i) from 0
//    forl(i,0,n) dp[i]=N;
//    dp[0]=0;
//    forl(i,1,n)
//    {
//        fore(j,1,2)
//        {
//            if(i-j>=0) dp[i]=min(dp[i],dp[i-j]+abs(arr[i]-arr[i-j]));
//        }
//    }
//    cout<<dp[n-1]<<endl;

}
