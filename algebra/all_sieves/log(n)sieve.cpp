#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define mp make_pair
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

//modify sieve to find smallest prime factor of a number
const int N=1e7+1;
int spf[N];//smallest prime factor of each number   
//O(nloglogn)
void sieve()
{
    spf[1]=1;
    forl(i,2,N)spf[i]=i;
    for(int i=4;i<N;i+=2) spf[i]=2;
    for(int i=3;i*i<N;i++)
    {
        if(spf[i]==i)
        {
            for(int j=i*i;j<N;j+=i)
            {
                if(spf[j]==j) spf[j]=i;
            }
        }
    }

}

//o(logn) per each query after the preprocessing
vector<int>getfactorization(int n)
{
    vector<int>res;
    while(n!=1)
    {
        res.pb(spf[n]);
        n/=spf[n];
    }

}

//continuosly divide by spf[n] to get power of each prime
vector<pair<ll,ll>> primepow(ll n) 
{ 
    ll curr = spf[n]; 
    ll cnt = 1;   
    vector<pair<ll,ll>>v;
    while (n > 1) 
    { 
        n /= spf[n]; 
        if (curr == spf[n]) 
        { 
            cnt++; 
            continue; 
        } 
  
        v.pb({curr,cnt});
        curr = spf[n]; 
        cnt = 1; 
    } 
    return v;
} 
int main()
{
    sieve();
}