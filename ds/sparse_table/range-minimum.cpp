#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef tree<int,int,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_map;
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
//use (__int128)to extend ll range

//O(nlogn) preprocessing with o(1) query time
//can handle only offline queries
int main()
{
    int n;
    cin>>n;
    int arr[n];
    forl(i,0,n) cin>>arr[i];
    int lookup[n][n];
    for(int leng=1;leng<=n;leng*=2)
    {
        fore(i,0,n-leng)
        {
            int j=i+leng-1;
            if(i==j)
            {
                lookup[i][i]=arr[i];
            }else{
                int mid=leng/2;
                lookup[i][j]=min(lookup[i][i+mid-1],lookup[j+1-mid][j]);
            }
        }
    }

    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        int leng=r-l+1;
        int ch=log2(leng);
        cout<<min(lookup[l][l+leng-1],lookup[r-leng+1][r])<<endl;;
    }
}