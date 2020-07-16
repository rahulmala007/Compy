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

// see this for doubt https://www.topcoder.com/community/competitive-programming/tutorials/introduction-to-string-searching-algorithms/

// we only consider proper prefixes
void build_lps_array(string t,int lps[])
{
    int m=t.len;

    lps[0]=0;  // empty string 
    lps[1]=0;  // single character

    // i represent the length of string under consideration not the position
    fore(i,2,m)
    {
        int j=lps[i-1];
        while(1)
        {
            if(t[i-1]==t[j])
            {
                lps[i]=j+1;
                break;
            }
            if(j==0)
            {
                lps[i]=0;
                break;
            }
            j=lps[j];
        }
    }
}

bool kmp(string s,string t,int lps[])
{
    int n=s.len;
    int m=t.len;
    int i=0;  // represents the state of the automata or the length of string matched till now
    int j=0;  // represent the pointer in string s
    bool ans=false;
    while(1)
    {
        if(j==n) break;

        if(s[j]==t[i])
        {
            i++;
            j++;
            if(i==m) 
            {
                ans=true;
                break;
            }
        }
        else{
            if(i>0) i=lps[i];
            else j++;
        }
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s,t;
        cin>>s>>t;
        int lps[t.len+1];
        build_lps_array(t,lps);
        cout<<kmp(s,t,lps)<<endl;
    }
}