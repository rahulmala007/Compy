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

//CODEFORCES 1321C --REMOVE ADJACENT

//This type of que deals with below scenarios

//if in a array we delete some range and then get  certain value and can use that to delete some range

//eg: if given a sequence of k's we can replace it by k-1
// 111"222"222 ----> 111"1"222--->"1111"222--->1"222"--->12
int main()
{

    // make two dps
    // dp stores if a sequence (i..j) can be destroyed to one number or not store tha t nnumber in dp[i][j]
    // use dp2 to find the minimum length of range(0..i) by iterating over all j such that 0<=j<i and dp2[i]=min(dp2[i],dp2[j]+val)
    //where value of val depends in (j..i) can be detroyed otr not which can be found using dp[j][i]
    int n;
    cin>>n;
    string s;
    cin>>s;
    int dp[n][n];
    forl(i,0,n)
    {
        forl(j,0,n)
        {
            if(i==j) dp[i][j]=s[i];
            else dp[i][j]=-1;
        }
    }
    forl(l,2,n+1)
    {
        fore(i,0,n-l)
        {
            int j=i+l-1;
            forl(k,i,j)
            {
                if(dp[i][k]!=-1 && dp[k+1][j]!=-1)
                {
                    if(abs(dp[i][k]-dp[k+1][j])==1) dp[i][j]=min(dp[i][k],dp[k+1][j]);
                }
                
            }
        }
    }
    int dp2[n];
    dp2[0]=1;
    forl(i,1,n) dp2[i]=i+1;

    forl(i,1,n)
    {
        if(dp[0][i]!=-1) dp2[i]=1;
        else{
            
            forl(j,0,i)
            {
                if(dp[j+1][i]!=-1)
                {
                    dp2[i]=min(dp2[i],dp2[j]+1);

                }else{
                    dp2[i]=min(dp2[i],dp2[j]+i-j);
                }
            }
        }
    }
    //forl(i,0,n) cout<<dp2[i]<<" ";
    cout<<n-dp2[n-1]<<endl;
   // cout<<endl;
}
