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

const int N=1e5+7;
ll segt[4*N+1]; 
ll lo[4*N+1]; 
ll hi[4*N+1]; 
ll delta[4*N+1];

void maketree(int i,int l,int r)
{
    lo[i]=l;
    hi[i]=r;
    segt[i]=0;
    delta[i]=0;
    if(l==r) return ;
    int mid=l+(r-l)/2;
    maketree(2*i,l,mid);
    maketree(2*i+1,mid+1,r);
}
void prop(int i)
{
    delta[2*i]+=delta[i];
    delta[2*i+1]+=delta[i];
    delta[i]=0;
}

void update(int i)
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
    prop(i);
    increment(2*i,l,r,val);
    increment(2*i+1,l,r,val);
    update(i); 
}

ll minimum(int i,int l,int r)
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
    int t;
    cin>>t;

    fore(test,1,t)
    {
        // char x;
        // cin>>x;
        int n,q;
        cin>>n>>q;
        maketree(1,0,n-1);
        ll arr[n];
        forl(i,0,n){
            cin>>arr[i];
            increment(1,i,i,arr[i]);
        }
        cout<<"Case "<<test<<":"<<endl;
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            l--;
            r--;
            cout<<minimum(1,l,r)<<endl;
        }
    }


}
