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


double doINF = 1.0/0.0 ;
ostream_iterator <int> outp(cout," ");


inline ll modadd(ll n,ll m,ll mod){
    ll sum = ((n+m)%mod+mod)%mod;
    return sum;
} 
inline ll modsub(ll n,ll m, ll mod){
    ll diff = ((n-m+mod)%mod+mod)%mod;
    return diff;
}
inline ll modpro(ll n,ll m,ll mod){
    ll pro = ((n*m)%mod+mod)%mod;
    return pro;
}
inline ll pow(int x,int y){
    ll res = 1;
    while (y > 0) {
        if (y & 1)
            res = res * x;
        y = y >> 1;
        x = x * x;
    }
    return res;
}
inline ll powmod(ll x,ll y,ll mod){
    ll res = 1;
    while (y > 0) {
        if (y & 1)
            res = modpro(res , x,mod);
        y = y >> 1;
        x = modpro(x , x,mod);
    }
    return res;
}
//ll min(ll a, ll b){
//    if(a>b){
//        return b;
//    }
//    return a;
//}
// 
//ll max(ll a, ll b){
//    if(a>b){
//        return a;
//    }
//    return b;
//}
bool pairdec(const pair<int,int> &a,  
               const pair<int,int> &b) 
{ 		if(a.fi!=b.fi)
       	return (a.fi> b.fi);
		else return a.se>b.se;  
} 
ll power(ll x, ll y, ll mod) 
{ 
    ll res = 1; 
    x = x%mod; 
    while (y > 0) { 
        if (y & 1) 
            res = (res * x) % mod; 
  
        y = y >> 1;
        x = (x * x) % mod; 
    } 
    return res; 
} 
ll modInverse(ll a, ll mod) 
{ 
    return  powmod(a, mod - 2, mod); 
} 
ll modFact(ll n, ll mod) 
{ 
    if (n >=mod) 
        return 0; 
  
    ll result = 1; 
    for (ll i = 1; i <= n; i++) 
        result = (result * i) %mod; 
  
    return result; 
} 
//cout<<setprecision(9)<<fixed<<sum<<endl; --- precision for double numbers
//copy(v.beg,v.en,outp);
//-----comparision for pairs------
 
//bool comp(const pair<int,int>pia,const pair<int,int>pib)
//{
//	if(pia.fi==pib.fi) return pia.se>pib.se;
//	else return pia.fi>pib.fi;
//}
 
//USE THIS CONSTANT
const int N=1e9+7;
int main()
{
    
}
