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

// minimum distance of all the vertices from a source vertex in  a weighted graph
const ll N=1e18;
void bell_ford(int v,vector<tuple<ll,ll,ll>>edge_set,ll dist[], int parent[])
{
    forl(i,0,v-1)
    {
        int check=0;
      forl(j,0,edge_set.si)
      {
          ll a,b,w;
          tie(a,b,w)=edge_set[j];
          if(dist[a]!=N && dist[a]+w<dist[b])        
          {
              dist[b]=dist[a]+w;  
              parent[b]=parent[a];  // while relaxing store the parent
              check=1;
          }
      }
      if(check==0) break;

    }

    return;
}

vector<int> print_shortest_path(int src,int dest,int parent[]) // note that it is one of the shortest paths 
{
    vector<int>v;
    int x=dest;
    while(x!=parent[x])
    {
        v.pb(x);
        x=parent[x];
    }
    v.pb(x);
    reverse(v.beg,v.en);
    return v;
}

vector<int>print_negative_cycle(int n,int x,int parent[])
{
    vector<int>v;
    forl(i,0,n) x=parent[x]; // start of the cycle
    int ptr=parent[x];
    v.pb(x);
    while(ptr!=x)
    {
        v.pb(ptr);
        ptr=parent[ptr];
    }
    return v;

}
int main()
{
    int v,e;
    cin>>v>>e;
    vector<int>adj[v+1]; //adj list not required here
    int parent[v+1]; // store the parent of the node in the tree formed
    vector<tuple<ll,ll,ll>>edge_set;
    forl(i,0,e)
    {
        ll a,b,w;
        cin>>a>>b>>w;
        adj[a].pb(b);
        adj[b].pb(a);
        edge_set.pb({a,b,w});
        edge_set.pb({b,a,w});
    }
    //let the source be the vertex 1 (change the source depending on  the question)
    int src=1;
    parent[src]=src;
    ll dist[v+1];

    // initialise the vertices with INF (change the value of INF depending on the question)
    forl(i,1,v+1)
    {
        dist[i]=N;
    } 
    dist[src]=0;
    bell_ford(v,edge_set,dist,parent);


    // check for negative cycles
    bool negative_cycle=false;
    int last_vertex=-1;
    forl(i,0,edge_set.si)
    {
        ll a,b,w;
        tie(a,b,w)=edge_set[i];
        if(dist[a]!=N && dist[a]+w<dist[b] )
        {
            negative_cycle=true;
            last_vertex=b;
        }
    }

    //printing the answer
    if(negative_cycle) 
    {
        cout<<"Constains a reachable negative cycle"<<endl;
        //printing the negative cycle
        vector<int>neg_cycle=print_negative_cycle(v,last_vertex,parent); // contains the negative cycle
        forl(i,0,neg_cycle.si)cout<<neg_cycle[i]<<" ";
        cout<<endl; 

    }
    else 
    {
        forl(i,1,v+1 )cout<<dist[i]<<" ";
        cout<<endl;
    }


    
    

}