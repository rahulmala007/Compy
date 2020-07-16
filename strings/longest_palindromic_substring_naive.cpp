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

// longest palindromic substring
// On^2) implementation

// iterate for the centre of the substring then we have two cases
// even length and odd length handle both in O(n) for each position os total O(n^2)

string longestpal(string s)
{
    int l=0;
    string ans="";
    int n=s.len;
    //odd 
    forl(c,0,n)
    {
        int i=c-1;
        int j=c+1;
        int temp=1;
        string temps="";
        temps+=s[c];
        while(i>=0 && j<=n-1)
        {
            if(s[i]==s[j])
            {
                i--;
                temp+=2;
                j++;
                string x="";
                string y="";
                x+=s[i];
                y+=s[j];
                temps.insert(0,x);
                temps+=y;

            }else break;
        }
        if(temp>l)
        {
            l=temp;
            ans=temps;
            
        }

    }

    // even
    forl(c1,1,n)
    {
        int c2=c1-1;
        int i=c2;
        int j=c1;
        int temp=0;
        string temps="";
        while(i>=0 && j<=n-1)
        {
            if(s[i]==s[j])
            {
                string x="";
                x+=s[i];
                temps.insert(0,x);
                temps+=s[j];
                temp+=2;
                i--;
                j++;

            }else break;
        }
        if(temp>l)
        {
            l=temp;
            ans=temps;
        }
    }
    // l gives the length of string
    return ans;
    
}
int main()
{
    cout<<longestpal("cacaccbabcabbbaacbbbbcaaaccaacbabcaccbccaacccaacbbaaabbbabcaaabc")<<endl;
}