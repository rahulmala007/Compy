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



//dfs for undirected graph
void dfs(int x,bool visited[],vector<int>adj[])
{
    stack<int>st;
    st.push(x);
    while(!st.empty())
    {
        int val=st.top();
        if(!visited[val])
        {
            cout<<val<<" ";
        }
        visited[val]=true;
        st.pop();
        for(auto node:adj[val])
        {
            if(!visited[node])
            {
                st.push(node);

            }
        }
    }
}
//input for undirected graph
void undirected_graph_input()
{
    int v,e;
    cin>>v>>e;
    bool visited[v+1];
    memset(visited,false,sizeof(visited));
    vector<int>adj[v+1];
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

//input for directed graph
void directed_graph_input()
{
    int v,e;
    cin>>v>>e;
    bool visited[v+1];
    memset(visited,false,sizeof(visited));
    vector<pair<int,int>>adj[v+1];
    forl(i,0,e)
    {
        int v1,v2,w;
        cin>>v1>>v2>>w;
        //v1-->{v2,w} edge is v1-->v2
        adj[v1].pb({v2,w});

    }
    return;
}


int main()
{
   int v,e;
    cin>>v>>e;
    bool visited[v+1];
    memset(visited,false,sizeof(visited));
    vector<int>adj[v+1];
    forl(i,0,e)
    {
        int v1,v2;
        cin>>v1>>v2;
        //change this for directed graph
        adj[v1].pb(v2);
        adj[v2].pb(v1);
    }
    dfs(1,visited,adj);
}