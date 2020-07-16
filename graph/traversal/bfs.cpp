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

//input for undirected graph
void undirected_graph_input()
{
    int v,e;
    cin>>v>>e;
    bool visited[v+1];
    ll dist[v+1];
    vector<int>adj[v+1];

    memset(dist,-1,sizeof(dist));
    memset(visited,false,sizeof(visited));
    
    forl(i,0,e)
    {
        int v1,v2;
        cin>>v1>>v2;
        //change this for directed graph
        adj[v1].pb(v2);
        adj[v2].pb(v1);
    }
    return;
}


//input for weighted_directed graph
void directed_graph_input()
{
    int v,e;
    cin>>v>>e;
    bool visited[v+1];
    ll dist[v+1];
    vector<pair<int,int>>adj[v+1];

    memset(dist,-1,sizeof(dist));
    memset(visited,false,sizeof(visited));

    
    forl(i,0,e)
    {
        int v1,v2,w;
        cin>>v1>>v2>>w;
        //v1-->{v2,w} edge is v1-->v2
        adj[v1].pb({v2,w});

    }
    return;
}


//bfs for unweighted_undirected graphs
void bfs(int x,bool visited[],vector<int>adj[],ll dist[])
{
    visited[x]=true;
    dist[x]=0;
    queue<int>q;
    q.push(x);
    while(!q.empty())
    {
        int val=q.front();
        cout<<val<<" ";
        q.pop();
        for(auto node:adj[val])
        {
            if(!visited[node])
            {
                q.push(node);
                dist[node]=dist[val]+1;
                visited[node]=true;
            }
        }
    }
}



//bfs for weighted_directed graphs
void bfs(int x,bool visited[],vector<pair<int,int>>adj[],ll dist[])
{
    //here dist represents the min distance from source according to weighted edges
    visited[x]=true;
    dist[x]=0;
    queue<int>q;
    q.push(x);
    while(!q.empty())
    {
        int val=q.front();
        cout<<val<<" ";
        q.pop();
        for(auto node:adj[val])
        {
            if(!visited[node.fi])
            {
                q.push(node.fi);
                dist[node.fi]=dist[val]+node.se;
                visited[node.fi]=true;
            }
        }
    }
}


const int N=1e5;
int main()
{
    
}
