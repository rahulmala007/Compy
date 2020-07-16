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

/*Approach
1)topological sort of all vertices 
2)now we get a linear ordering of vertices where edges go from i->j iff i<j
3)perform a dp on the topological ordering to get the answer
4)we might need a reverse adjacent to know which vertices have edges into the current vertex while performing the dp
*/

// getting the topological ordering
vector<int>topo;
const int N=1e5+10;
bool visited[N];
void dfs(int s,vector<int>adj[])
{
    visited[s]=true;
    for(auto node:adj[s])
    {
        if(!visited[node])dfs(node,adj);
    }
    topo.pb(s);
}


int main()
{
    int n,m;
   cin>>n>>m;
   vector<int>adj[n+1];
   vector<int>adj2[n+1];
   forl(i,0,m)
   {
       int a,b;
       cin>>a>>b;
       adj[a].pb(b);
       adj2[b].pb(a);
   }

   //topological ordering code
   forl(i,1,n+1) 
   {
       if(!visited[i]) dfs(i,adj);
   }
   reverse(topo.beg,topo.en);

   //simple dp on the topological ordering
   int dp[n];
   forl(i,0,n) dp[topo[i]]=0;
   int maxi=0;
   forl(i,1,n)
   {
       for(auto node:adj2[topo[i]])
       {
           dp[topo[i]]=max(dp[topo[i]],1+dp[node]);
       }
       maxi=max(maxi,dp[topo[i]]);
   }
   cout<<maxi<<endl;
   
}
