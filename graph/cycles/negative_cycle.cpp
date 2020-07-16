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

/*  Approach:
1) Using bellman ford algo   // O(N*M)
Do n-1 iterations of the bellman ford algo if there is nth iteration possible then there is a negative cycle present;
**** PRINTING THAT CYCLE:
1)store the node that violated that got relaxed in the nth iteration of bellman ford
2)use the parent array and go back n times 
3)now find the cycle from this node

2)Use floyd warshal
In the final matrix check for d[v][v]<0

***PRINTING THE CYCLE:

*/
int main()
{
    int n,m;
    cin>>n
}

