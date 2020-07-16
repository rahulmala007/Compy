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

struct segnode{
    ll val;
    ll lo;
    ll hi;
    ll delta;
    segnode()
    {
        val=0;
        lo=0;
        hi=0;
        delta=0;
    }
};
const int N=2e5+7;
segnode segtree[4*N]; // 1 based indexing
void maketree(ll i,ll l,ll r)
{
    segtree[i].hi=r;
    segtree[i].lo=l;
    if(l==r) return ;
    ll mid=l+(r-l)/2;
    maketree(2*i,l,mid);
    maketree(2*i+1,mid+1,r);
}

//change this update function wrt to the question
void update(ll i)
{
    segtree[i].val=min(segtree[2*i].val+segtree[2*i].delta,segtree[2*i+1].val+segtree[2*i+1].delta);
}
void prop(ll i)
{
    segtree[2*i].delta+=segtree[i].delta;
    segtree[2*i+1].delta+=segtree[i].delta;
    segtree[i].delta=0;
}

//range update (use l==r==i for point update)
void increment(ll i,ll l,ll r,ll val)
{
    //disjoint
    if(segtree[i].lo>r || segtree[i].hi<l) return;

    // complete cover
    if(segtree[i].lo>=l && segtree[i].hi<=r)
    {
        segtree[i].delta+=val;
        return ;
    }
    //partial cover
    prop(i);
    increment(2*i,l,r,val);
    increment(2*i+1,l,r,val);
    update(i);
}

//change wrt to question
const ll INF=1e18;
ll rangemin(ll i,ll l,ll r)
{
    if(segtree[i].lo>r || segtree[i].hi<l) return INF;

    // complete cover
    if(segtree[i].lo>=l && segtree[i].hi<=r)
    {
        return segtree[i].delta+segtree[i].val;
    }
    //partial cover
    prop(i);
    ll left=rangemin(2*i,l,r);
    ll right=rangemin(2*i+1,l,r);
    update(i);
    return min(left,right);
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
        cout<<rangemin(1,a,b)<<endl;
    }

}