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
#define ld long double


//recursive
ll recbinpow(ll a,ll n)
{
    if(n==0) return 1;
    if(n%2==0)
    {
        ll val=recbinpow(a,n/2);
         return val*val;
    }
    else 
    {   
        ll val=recbinpow(a,(n-1)/2);
        return val*val*a;
    }
}

//iterative
ll binpow(ll a,ll n)
{
    ll ans=1;
    while(n>0)
    {
        if(n&1) ans=ans*a;
        a=a*a;
        n=n>>1;     
    }
    return ans;
}


ll modbinpow(ll a,ll n,ll mod)
{
    a%=mod;
    ll ans=1;
    while(n>0)
    {
        if(n&1)
        {
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        n>>=1;
    }
    return ans%mod;

}

int main()
{
   cout<<binpow(7,3)<<endl;

}