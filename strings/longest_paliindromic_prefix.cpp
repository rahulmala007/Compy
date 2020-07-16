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
#define ld long double

// for doubt use this https://leetcode.com/problems/shortest-palindrome/discuss/60204/using-kmps-lps-longest-prefix-suffix-computation-to-solve-in-linear-on-time
// similar for longest palindromic suffix === longest palindromic prefix (reverse(string))

//O(n)

// kmp lps code
vector<int>lps(string &s)
{
    int n=s.len;
    vector<int>v;
    v.pb(0);
    v.pb(0);
    forl(i,2,n+1)
    {
        int j=v[i-1];
        while(1)
        {
            if(s[i-1]==s[j]) 
            {
                v.pb(j+1);
                break;
            }
            if(j==0)
            {
                v.pb(0);
                break;
            }
            j=v[j-1];
        }
    }
    return v;
}

int main()
{
    string s;
    cin>>s;
    // longest prefix
    string temps=s;
    reverse(temps.begin(),temps.end());
    string news=s+"#"+temps;
    vector<int>v=lps(news);
    cout<<v[v.size()-1]<<endl; // length of longest palindromic prefix 

}