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

const int N=1e5;
int parent[N];
int ranks[N];
// by using both path-compression and union by rank or size we get O(1) time amortized.
// on worst case we can get O(logn) time

// on using without path compression we get O(logn ) time per query


//path-compression
int find_set(int v)
{
    if(v==parent[v]) return v;
    else return parent[v]=find_set(parent[v]);
}


// using union by rank(based on the depth of trees)
void make_set(int v)
{
    parent[v]=v;
    ranks[v]=0;
}

void union_sets(int a,int b)
{
    a=find_set(a);
    b=find_set(b);
    if(a==b) return;
    else{
        if(ranks[a]<ranks[b]) swap(a,b);
        parent[b]=a;
        if(ranks[a]==ranks[b]) ranks[a]++;
    }
}


int main()
{

}