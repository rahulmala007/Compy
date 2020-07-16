#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define mp make_pair
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

//!!REMEMBER USE (__int128)to get higher value than 10^18 with long long //(may not work in codeforces)
// gcd with long long
ll gcd(ll a,ll b)
{
    if(b==0)return a;
    else return gcd(b,a%b);
}


//ncr
ll NcR(ll n, ll r) 
{ 
    ll p = 1, k = 1; 
    if (n - r < r) 
        r = n - r; 
  
    if (r != 0) { 
        while (r) { 
            p *= n; 
            k *= r; 

            ll m = __gcd(p, k); 

            p /= m; 
            k /= m; 
  
            n--; 
            r--; 
        } 
    }  
    else p = 1;
    return p;
} 


// sieve of erasthoneses
const int N=1e3;
bool isprime[N];
void sieve()
{
    memset(isprime,true,sizeof(isprime));
    isprime[0]=isprime[1]=false;
    for(int i=2;i*i<=N;i++)
    {
        if(isprime[i])
        {
            for(int j=i*i;j<=N;j+=i)
            {
                isprime[j]=false;
            }
        }
    }
}


int main()
{
  int n;
  cin>>n;
  vector<int>v;
  forl(i,0,n) 
  {
      int x;
      cin>>x;
      v.pb(x);
  }
  int x=n-1;
  vector<int>ans;
  rfor(i,n-1,0)
  {
      if(v[i]<9)
      {
          ans.pb(v[i]+1);
          x=i;
          break;
      }
      else{
          ans.pb(0);
      }
  }
  rfor(i,x-1,0)
  {
      ans.pb(v[i]);
  }
  reverse(ans.beg,ans.en);
  vector<int>fans;
  int num=0;
  while(ans[num]==0) num++;
  forl(i,num,ans.si) fans.pb(ans[i]);
  forl(i,0,fans.si) cout<<fans[i]<<" ";
  cout<<endl;


}
