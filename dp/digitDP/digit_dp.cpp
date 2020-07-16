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

// for all numbers in the range [a,b] find the number of numbers divisible by k
const ll N=1e4+10;
ll ans(string s,ll k)
{
     int n=s.len;
    vector<vector<ll>>dp(k,vector<ll>(2));
    dp[0][0]=1;
    fore(i,0,n)
    {
        vector<vector<ll>>newdp(k,vector<ll>(2));
        forl(j,0,k)
        {
            forl(t,0,2)
            {
                forl(digit,0,10)
                {
                    if(t==0 && digit>s[i]-'0') break;
                    if(t==0)
                    {
                        if(digit==s[i]-'0')
                        {
                            newdp[(digit+j)%k][0]+=dp[j][0];
                        }else{
                            newdp[(digit+j)%k][1]+=dp[j][0];
                        }
                    }
                    else {
                        newdp[(digit+j)%k][1]+=dp[j][1];

                    }
                }
            }
        }
        dp=newdp;
    }
    return dp[0][0]+dp[0][1];
    
}
void solve()
{
    ll a,b;
    cin>>a>>b;
    ll k;
    cin>>k;
    cout<<ans(to_string(b),k)-ans(to_string(a-1),k)<<endl;
}
int main()
{
    fastio;
    int test;
    cin>>test;
    forl(t,1,test+1)
    {

        cout<<"Case "<<t<<": ";
        solve();
        
    }

}
