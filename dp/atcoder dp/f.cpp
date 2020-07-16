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
    string s,t;
    cin>>s>>t;
    int n=s.len;
    int m=t.len;
    int dp[n][m];
    forl(i,0,n) forl(j,0,m) dp[i][j]=0;
    //dp[i][j]------ means consider s(0..i) and t(0...j)
    // if s(i)==t(j) then check (i-1,j-1)+1,(i-1,j),(i,j-1)
    //else check (i-1,j) and (i,j-1)
    int maxn=n+1;
    int maxm=m+1;
    forl(i,0,n){
        if(s[i]==t[0])
        {
            maxn=i;
            break;
        }
    }

    forl(i,0,m){
        if(t[i]==s[0])
        {
            maxm=i;
            break;
        }
    }


    forl(i,maxn,n)
    {
        dp[i][0]=1;
    }

    forl(i,maxm,m)
    {
        dp[0][i]=1;
    }
    forl(i,1,n)
    {
        forl(j,1,m) 
        {
            if(s[i]==t[j]) dp[i][j]=max(dp[i-1][j-1]+1,max(dp[i-1][j],dp[i][j-1]));
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
         }
    }
    //cout<<dp[n-1][m-1]<<endl;
    int i=n-1,j=m-1;
    vector<char>v;

    //heree check which condition was folowed and track the dp transitions
    while(i>=0 && j>=0)
    {
        if(i==0){
            if(dp[i][j])v.pb(s[i]);
            break;
        }
        if(j==0)
        {
            if(dp[i][j])v.pb(t[j]);
            break;
        }
        if(s[i]==t[j])
        {
            if(dp[i-1][j-1]+1==max(dp[i-1][j-1]+1,max(dp[i-1][j],dp[i][j-1]))) 
            {
                v.pb(s[i]);
                i--;
                j--;

            }else if(dp[i-1][j]==max(dp[i-1][j-1]+1,max(dp[i-1][j],dp[i][j-1])))
            {
                i--;
            }else j--;
        }
        else 
        {
            if(dp[i-1][j]==max(dp[i-1][j],dp[i][j-1])) 
            {
                i--;
            }else j--;
        }
    }

    rfor(i,v.si-1,0) cout<<v[i];
    cout<<endl;
}
