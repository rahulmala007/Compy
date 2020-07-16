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

//query here is to get the sum between [1...x]
ll query(ll bit[],int n,int x)
{
    x++;
    ll sum=0;
    while(x>0)
    {
        sum+=bit[x];
        x-=(x&(-x));
    }
    return sum;
}

//update here means increase the value by val
void update(ll bit[],int n,int x,ll val) 
{
    x++;
    while(x<=n)
    {
        bit[x]+=val;
        x+=(x&(-x));
    }
}


//nlogn
void makebit(ll bit[],int arr[],int n)
{
    forl(i,0,n+1) bit[i]=0;
    forl(i,0,n) update(bit,n,i,arr[i]);
}

int main()
{
    

}
