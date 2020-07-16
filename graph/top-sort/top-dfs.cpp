#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
bool visited[N];
vector<int>ans;
void dfs(int v,vector<int>adj[])
{
    visited[v]=true;
    for(auto node:adj[v])
    {
        if(!visited[node])dfs(node,adj);
    }
    ans.pb(v);
}

//reverse sort on the basis of dfs finish times
void top_sort(int v,vector<int>adj[])
{
    ans.clear();
    memset(visited,false,sizeof(visited));
    forl(i,1,n+1)
    {
        if(!visited[i])
        {
            dfs(i,adj);
        }
    }
    reverse(ans.beg,ans.en);
}
int main()
{


}