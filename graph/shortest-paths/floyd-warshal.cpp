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

int dist[N][N];
int parent[N][N];


void floyd(int n)
{
    //chose k as the intermediate vertex
    forl(k,0,n)
    {
        forl(i,0,n)
        {
            forl(j,0,n)
            {
                if(dist[i][k]<INF && dist[k][j]<INF) //this is required to hande the negative edges in implementation
                {
                    if(dist[i][j]>dist[i][k]+dist[k][j])
                    {   
                        dist[i][j]=dist[i][k]+dist[k][j];
                        parent[i][k]=i;
                        parent[k][j]=k;
                        parent[i][j]=k;
                    }

                    
                    
                    
                } 
                
            }
        }
    }
}

//find pairs which have reachable negative cycles in their shortest paths

void check_negative(int n)
{
    forl(i,0,n)
    {
        forl(j,0,n)
        {
            forl(k,0,n)
            {
                if(dist[i][k]<INF && dist[k][j]<INF && dist[k][k]<0)
                {
                    dist[i][j]=-INF;
                } 
            }
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    int adj[n][n];
    forl(i,0,n)
    {
        forl(j,0,n)
        {
            if(i==j) 
            {
                adj[i][j]=0;
                parent[i][j]=i;
            }
            else 
            {
                adj[i][j]=INF;
                parent[i][j]=-1;
            }
            dist[i][j]=adj[i][j];

        }
    }
    forl(i,0,m)
    {
        int x,y,w;
        cin>>x>>y>>w;
        adj[x][y]=w;
        parent[x][y]=x;
    }

    floyd(n);
    



    

}