
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
inline ll modadd(ll n,ll m,ll mod){
    ll sum = ((n+m)%mod+mod)%mod;
    return sum;
} 

inline ll modsub(ll n,ll m, ll mod){
    ll diff = ((n-m+mod)%mod+mod)%mod;
    return diff;
}
const ll N=1e9+7;
int main()
{
    int n;
    cin>>n;
    int arr[n][n];
    forl(i,0,n) forl(j,0,n) cin>>arr[i][j];
    forl(i,0,n)
    {
        forl(j,0,n)
        {
            if(arr[i][j]==1)
        }
    }
}

