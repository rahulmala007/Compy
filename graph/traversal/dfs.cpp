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


const int V=1e3;
// global visited array
bool visited[V+1];
void dfs(int x,vector<int>adj[])
{
    visited[x]=true;
    cout<<x<<" ";
    for(auto node:adj[x])
    {
        if(!visited[node]) dfs(node,adj);
    }
    return ;
}
int main()
{
    int v,e;
    cin>>v>>e;
    vector<int>adj[v+1];
    forl(i,0,e)
    {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    fore(i,1,v)
    {
        if(!visited[i]) dfs(i,adj);
    }
}