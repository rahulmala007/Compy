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
//using disjoint set union O(mlogn)
int find_set(int v)
{
    if(v==parent[v]) return v;
    else return parent[v]=find_set(parent[v]);
}

void make_set(int v)
{
    parent[v]=v;
    rank[v]=0;
}

void union_sets(int a,int b)
{
    a=find_set(a);
    b=find_set(b);
    if(a==b) return;
    else{
        if(rank[a]<rank[b]) swap(a,b);
        parent[b]=a;
        if(rank[a]==rank[b]) rank[a]++;
    }
}

struct edge{

    int u,v;
    ll w;
    bool operator < (Edge const & other)
    {
        return w<other.w;
    }
};

void kruskal(int n,vector<edge>edge_list)
{
    ll mst_weight=0;
    vector<pair<int,int>>connected;
    forl(i,0,n) make_set(i);
    sort(edge_list.beg,edge_list.en);
    for(auto edge:edge_list)
    {
        if(connected.si==n-1) break;
        if(find_set(edge.u)!=find_set(edge.v))
        {
            mst_weight+=edge.w;
            connected.pb({u,v});
            union_sets(edge.u,edge.v);
        }
    }
}
int main()
{

}