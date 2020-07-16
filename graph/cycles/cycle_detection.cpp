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


//O(V+E) using bfs (simple and connected )
// for disconnected run bfs on whole graph(using every non visited node)
bool cycle_detection(int x,bool visited[],vector<int>adj[])
{
    queue<int>q;
    visited[x]=true;
    q.push(x);
    int ch=false;
    while(!q.empty())
    {
        int val=q.front();
        q.pop();
        int sum=0;
        for(auto node:adj[val])
        {
            if(!visited[node])
            {
                q.push(node);
                visited[node]=true;
            }else sum++;
        }
        if(sum>=2) ch=true;
    }
    return ch;
}

//cycle detection using iterative dfs
bool cycle_detection2(int x,bool visited[],vector<int>adj[])
{
    stack<int>st;
    st.push(x);
    while(!st.empty())
    {
        int val=st.top();
        
        st.pop();
        if(visited[val]) continue;
        else visited[val]=true;
            
        int sum=0;
        for(auto node:adj[val])
        {
            if(!visited[node])
            {
                st.push(node);
            }else sum++;
        }
        if(sum>=2) return true;
    }
    return false;
}

int main()
{
    int v,e;
    cin>>v>>e;
    bool visited[v+1];
    ll dist[v+1];
    vector<int>adj[v+1];

    memset(dist,-1,sizeof(dist));
    memset(visited,false,sizeof(visited));
    bool self_loops=false;
    forl(i,0,e)
    {
        int v1,v2;
        cin>>v1>>v2;
        //if self loops can exist directly check them here
        if(v1==v2) self_loops=true;
        adj[v1].pb(v2);
        
        adj[v2].pb(v1);
    }
    bool ans=cycle_detection2(1,visited,adj) && self_loops;
    cout<<ans<<endl;
}

// note cycle can also be detected if for a connected component having c nodes there are more than c-1 edges then there must be a cycle else not

// to print the cycle:
// 1) store the node the cycle_detection gives false
// 2) store parent[node] while performing bfs or dfs
// 3) from that node and parent array print the cycle   




