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

vector<int>primes;
void sieve(int limit)
{
    bool isprime[limit+1];
    memset(isprime,true,sizeof(isprime));
    for(int i=2;i*i<limit;i++)
    {
        if(isprime[i])
        {
            for(int j=i*i;j<limit;j+=i)
            {
                isprime[j]=false;
            }
        }
    }
    for(int i=2;i<limit;i++)
    {
        if(isprime[i]) primes.pb(i);
    }
}


void segsieve(int n)
{
    int limit=floor(sqrt(n))+1;
    sieve(limit);
    int l=limit;
    int h=2*limit;
    while(l<=n)
    {
        if(h>n) h=n;
        bool isprime[limit+1];
        memset(isprime,true,sizeof(isprime));
        for(int i=0;i<primes.size();i++)
        {
            int llim=floor(l/primes[i])*primes[i];
            if(llim<l) llim+=primes[i];
            for(int j=llim;j<h;j+=primes[i])
            {
                isprime[j-l]=false;
            }
        }

        for(int i=l;i<h;i++) 
        {
            if(isprime[i-l]) primes.pb(i);
        }
        l+=limit;
        h+=limit;
    }
}
int main()
{
    primes.clear();
    segsieve(100);
    forl(i,0,primes.size())
    {
        cout<<primes[i]<<" ";
    }
    cout<<endl;
}