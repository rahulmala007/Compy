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

//using bfs coloring the vertex then checking if edge goes from different color or not
bool isbipartite(int x,bool visited[],vector<int>adj[],int color[])
{
    queue<int>q;
    q.push(x);
    visited[x]=true;
    color[x]=1;
    while(!q.empty())
    {
        int val=q.front();
        q.pop();
        for(auto node:adj[val])
        {
            if(!visited[node])
            {
                q.push(node);
                visited[node]=true;
                color[node]=1-color[val];
            }

        }
    }

}

//using dfs
bool isbipartite2(int x,bool visited[],vector<int>adj[],int color[])
{
   stack<int>st;
    st.push(x);
    color[x]=0;
    while(!st.empty())
    {
        int val=st.top();
        visited[val]=true;
        st.pop();
        for(auto node:adj[val])
        {
            if(!visited[node])
            {
                st.push(node);
                color[node]=1-color[val];

            }
        }
    }


}


//input for undirected graphs
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
const int N=1e5;
int main()
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
   int color[v+1];
   forl(i,1,v)
   {
       if(!visited[i])isbipartite2(i,visited,adj,color);
   }
    int ch=1;
   forl(i,1,v+1)
   {
       forl(j,0,adj[i].si)
       {
           if(color[j]==color[i])ch=0;
       }
   }
   if(ch) cout<<"YES"<<endl;
   else cout<<"NO"<<endl;

}

// k coloring problem for k>=3 is NP hard