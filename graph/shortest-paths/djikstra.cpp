#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
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
#define pii pair<int,int>
const int N=1e3;
const int INF=1e9+7;


//o(vlogv + e) approach
void djikstra(int s,vector<pair<int,int>>adj[],int dist[],int parent[],int n)
{
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    forl(i,1,n+1)pq.push({dist[i],i});
    while(!pq.empty())
    {
        int v=pq.top().se;
        int d=pq.top().fi;
        if(dist[v]==INF) break;
        pq.pop();
        if(d!=dist[v])continue;
        for(auto nodepair:adj[v])
        {
            int node=nodepair.fi;
            int wt=nodepair.se;
            if(dist[v]+wt<dist[node])
            {
                parent[node]=v;
                dist[node]=dist[v]+wt;
                pq.push({dist[node],node});
            }
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;   
    vector<pair<int,int>>adj[n+1];
    bool visited[n+1];
    int parent[n+1];
    int dist[n+1];
    forl(i,0,n+1) parent[i]=-1;
    forl(i,0,m)
    {
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].pb({y,w});
    }
    memset(visited,false,sizeof(visited));
    int src;
    cin>>src;
    parent[src]=src;
    forl(i,0,n+1)dist[i]=INF;
    dist[src]=0;  

    //run djikstra now  



}