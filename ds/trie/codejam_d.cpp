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

const int N=2e6;
struct node{
    ll more;
    ll eq;
    ll child[26];
    node()
    {
        memset(child,-1,sizeof(child));
        more=0;
        eq=0;
    }
};
vector<node>trie;

void initialise()
{
    node nullnode;
    nullnode.eq=-1;
    trie.pb(nullnode);
}
void insert(string s)
{
    ll now=0;
    forl(i,0,s.len)
    {
        int value=s[i]-'A';
        if(trie[now].child[value]==-1)
        {
            node newnode;
            trie[now].child[value]=trie.size();
            trie.pb(newnode);
        }
        now=trie[now].child[value];
        trie[now].more++;
        if(i==s.len-1) trie[now].eq++;
        
    }
}
ll ps=0;
ll rec(ll pos,ll k)
{
    if(trie[pos].eq==trie[pos].more) return ps*(trie[pos].eq/k);
    else{
        ps++;
        ll val=0;
        ll here=trie[pos].eq;
        forl(i,0,26)
        {
            if(trie[pos].child[i]!=-1)
            {
                
                val=val+rec(trie[pos].child[i],k);
                here=here+(trie[trie[pos].child[i]].eq+k)%k;
            }
        }
        trie[pos].eq=here;
        ps--;
        return val+ps*(here/k);
    }

}

void printtrie(string s)
{
    int now=0;
    forl(i,0,s.len)
    {
        now=trie[now].child[s[i]-'a'];
        cout<<s[i]<<"---"<<trie[now].more<<" "<<trie[now].eq;
    }
    cout<<endl;
}
int main()
{
    int t;
    cin>>t;
    forl(i,1,t+1)
    {
        trie.clear();
        initialise();
        ll n,k;
        cin>>n>>k;
        forl(i,0,n) 
        {
            string s;
            cin>>s;
            insert(s);
            // printtrie(s);
        }
        cout<<"Case #"<<i<<": "<<rec(0,k)<<endl;
    }
}


