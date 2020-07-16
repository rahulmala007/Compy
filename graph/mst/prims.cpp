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
const ll INF=1e18;
struct edge
{
    ll w=INF;
    ll to=-1;
};

//O(n^2) for dense graphs
void prim(int n,vector<vector<int>>adj)
{
     ll mst_weight=0; // value of mst weight
    bool mst_exist=true;

    vector<bool>selected(n,false); // whether the vertex is currently in the mst
    vector<pair<int,int>>connected; // gives the edges which belong to the mst

    vector<edge>mini(n); // minimum edge to the the selected portion from each vertex
    mini[0].w=0; // start the process with vertex 0 (we can start with any vertex)
   
   


     // change start and end wrt to the limit of vertices you are using 
    forl(i,0,n)
    {
        int v=-1; // the vertex whose edge weight connected to selected portion is minimum
        forl(j,0,n)
        {
            if(!selected[j] && (v==-1 || mini[j].w<mini[v].w)) v=j;
        }
        selected[v]=true;
        mst_weight+=mini[v].w;
        if(min[v].w==INF) mst_exist=false;   // if weight of minimum edge is INF then mst doest exist
        if(min[v].to!=-1)connected.pb({to,v}); 

        //now adjust as v is now added to the mst
        forl(to,0,n)
        {
            if(adj[v][to]<mini[to].w) 
            {
                mini[to]={adj[v][to],v};
            }
        }


    }
}

// O(mlogn) using priority queue for sparse graphs

int main()
{

}