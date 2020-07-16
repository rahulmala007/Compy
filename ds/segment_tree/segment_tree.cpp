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
//we can do range min,max,gcd,xor,and..

//Range Minimum Query Problem


const int N=2e5+7;
ll segt[4*N+1]; //1 based indexing
ll lo[4*N+1]; //low of ith node
ll hi[4*N+1]; //high of ith node
ll delta[4*N+1]; //lazy propogation part

void maketree(int i,int l,int r)
{
    lo[i]=l;
    hi[i]=r;
    if(l==r) return ;
    int mid=l+(r-l)/2;
    maketree(2*i,l,mid);
    maketree(2*i+1,mid+1,r);
}
void prop(int i) //here we are incrementing change wrt to function needed
{
    delta[2*i]+=delta[i];
    delta[2*i+1]+=delta[i];
    delta[i]=0;
}

void update(int i) //for RMQ updation
{
    segt[i]=min(segt[2*i]+delta[2*i],segt[2*i+1]+delta[2*i+1]);
   
}

void increment(int i,int l,int r,ll val)
{
    if(hi[i]<l || lo[i]>r) return ;
    if(lo[i]>=l && hi[i]<=r)
    {
        delta[i]+=val;
        return;
    }
    //partial cover
    prop(i);
    increment(2*i,l,r,val);
    increment(2*i+1,l,r,val);
    update(i); 
}

ll minimum(int i,int l,int r) //change this function wrt to the operation needed
{
    if(r<lo[i] || l>hi[i]) return LONG_LONG_MAX;
    if(l<=lo[i] && r>=hi[i]) return segt[i]+delta[i];

    prop(i);
    ll mleft=minimum(2*i,l,r);
    ll mright=minimum(2*i+1,l,r);
    update(i);
    return min(mleft,mright);
}

int main()
{
    fastio;
    ll n,q;
    cin>>n>>q;
    maketree(1,1,n);
    ll arr[n+1];
    forl(i,1,n+1)
    {
        cin>>arr[i];
        increment(1,i,i,arr[i]);
    }
    while(q--)
    {
        ll a,b;
        cin>>a>>b;
        cout<<minimum(1,a,b)<<endl;
    }



}
