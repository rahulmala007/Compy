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
const ll NINF=-1e18+5;
ll max_sum_subarray(ll arr[],int n)
{
    ll best_sum=NINF;
    ll val_so_far=0;
    forl(i,0,n)
    {
        val_so_far+=arr[i];
        best_sum=max(best_sum,val_so_far);
        val_so_far=max(val_so_far,0LL);
    }
    return best_sum;
}
int main()
{

}
