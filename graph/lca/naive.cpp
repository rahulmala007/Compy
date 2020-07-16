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

const int N=1e5+7;
int parent[N];
int height[N];
bool visited[N]; // we may not need this as it is a tree 
void dfs(int x,vector<int>adj[],int h,int par)
{
    parent[x]=par;
    height[x]=h;
    visited[x]=true;
    for(auto node:adj[x])
    {
        if(!visited[node])
        {
            dfs(node,adj,h+1,x);
        }
    }
}

// o(n) lca
int lca(int a,int b)
{
    if(height[b]<height[a]) swap(a,b);
    int d=height[b]-height[a];
    while(d>0)
    {
        b=parent[b];
        d--;
    }
    if(a==b) return a;
    while(parent[a]!=parent[b]) 
    {
        a=parent[a];
        b=parent[b];
    }
    return parent[a];
}
int main()
{
    int n,m;
    cin>>n>>m;
    memset(visited,false,sizeof(visited));
    vector<int>adj[n+1];
    forl(i,0,m)
    {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    //let the root be 1
    dfs(1,adj,0,-1);
}
