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
#define ld long double
inline ll modpro(ll n,ll m,ll mod){
    ll pro = ((((n+mod)%mod)*((m+mod)%mod)+mod)%mod+mod)%mod;
    return pro;
}
inline ll modadd(ll n,ll m,ll mod){
    ll sum = (((n%mod)+(m%mod))%mod+mod)%mod;
    return sum;
} 
//C=A*B multiply 2X2 matrix
const ll mod=1e9+7;
const int N=101;
void matrixmul(ll a[][N],ll b[][N],ll c[][N],ll n )
{

    ll temp[n+1][N];
    forl(i,1,n+1)
    {
        forl(j,1,n+1)
        {
            temp[i][j]=0;
            forl(k,1,n+1)
            {
               temp[i][j]+=(((a[i][k]%mod)*(b[k][j]%mod))%mod);
               if(temp[i][j]>=mod) temp[i][j]-=mod;
            }
        }
    }

   forl(i,1,n+1)
   {
       forl(j,1,n+1)
       {
           c[i][j]=temp[i][j];
       }
   }
}

//ans=A^N
void matrixexpo(ll a[][N],ll ans[][N],ll n,ll k)
{
    //initially ans=I
    forl(i,1,n+1)
    {
        forl(j,1,n+1)
        {
            if(i==j)ans[i][j]=1;
            else ans[i][j]=0;
        }
    }
    while(k>0)
    {
        if(k&1LL) matrixmul(ans,a,ans,n);
        matrixmul(a,a,a,n);
        k>>=(1LL);
    }
}

//n^3log(k)
int main()
{
    fastio;
   ll n,m,k;
   cin>>n>>m>>k;
   ll adj[n+1][N];
   forl(i,0,n+1) forl(j,0,n+1) adj[i][j]=0;
   forl(i,0,m)
   {
       ll a,b;
       cin>>a>>b;
       adj[a][b]=1;
   }
   ll ans[n+1][N];
   matrixexpo(adj,ans,n,k);
   ll sum=0;
   forl(i,1,n+1)
   {
       forl(j,1,n+1)
       {
           sum=modadd(sum,ans[i][j],mod);
       }
   }
   cout<<sum<<endl;

}