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

ll gcd(ll a,ll b)
{
    if(a==0) return b;
    else return gcd(b%a,a);
}

// gcd(a,b)=a*x+b*y
ll x=1;
ll y=1;
ll extended_gcd(ll a,ll b)
{
    if(a==0)
    {
        x=0;
        y=1;
        return b;
    }
    else{
        ll x1,y1;
        ll d=extended_gcd(b%a,a);
        y1=x;
        x1=y-x*(b/a);
        x=x1;
        y=y1;
        return d;
    }
}
int main()
{
    
}