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

//C=A*B multiply 2X2 matrix
const ll mod=1e9+7;
void matrixmul(ll a[2][2],ll b[2][2],ll c[][2] )
{

    ll temp[2][2];
    forl(i,0,2)
    {
        forl(j,0,2)
        {
            temp[i][j]=0;
            forl(k,0,2)
            {
               temp[i][j]+=(a[i][k]*b[k][j]);
            }
        }
    }

   forl(i,0,2)
   {
       forl(j,0,2)
       {
           c[i][j]=temp[i][j];
       }
   }
}

//ans=A^N
void matrixexpo(ll a[2][2],ll ans[2][2],ll n)
{
    //initially ans=I
    forl(i,0,2)
    {
        forl(j,0,2)
        {
            if(i==j)ans[i][j]=1;
            else ans[i][j]=0;
        }
    }
    while(n>0)
    {
        if(n%2) matrixmul(ans,a,ans);
        matrixmul(a,a,a);
        n/=2;
    }
}

int main()
{
   ll n;
   cin>>n;
   //f0=0 f1=1
   if(n==0)
   {
       cout<<0<<endl;
       return 0;
   }
   ll F[2][2] = {{1,1}, {1,0}} ; 
   ll ans[2][2];
   matrixexpo(F,ans,n-1);
   cout<<ans[0][0]<<endl;

}