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

struct node{
    int val;
    int child[2];
    node()
    {   val=0;
        memset(child,-1,sizeof(child));
    }
};

vector<node>trie;

void initialise()
{
    trie.clear();
    node newnode;
    trie.pb(newnode);
}
void insert(string s)
{
    int now=0;
    forl(i,0,s.len)
    {   
        int index=s[i]-'0';
        if(trie[now].child[index]==-1)
        {
            node newnode;
            trie[now].child[index]=trie.si;
            trie.pb(newnode);

        } 
        now=trie[now].child[index];
        trie[now].val++;

    }
}

// maximum xor betweeen any two elements of a array
string maxxor(string s)
{
    int now=0;
    string maxval="";
    forl(i,0,s.len)
    {
        int num=s[i]-'0';
        int tofind=(num^1);
        if(trie[now].child[tofind]!=-1)
        {
            maxval.pb('1');
            now=trie[now].child[tofind];
        }else{
            int number=1-tofind;
            maxval.pb('0');
            now=trie[now].child[1-tofind];
        }
    }
    return maxval;
}

//maximum xor subarray f[l..r]=f[1...r]^f[1..l-1]
string maxi(string a,string b)
{
    if(a=="") return b;
    else if(b=="")return a;
    forl(i,0,a.len)
    {
        if(a[i]-'0'>b[i]-'0') return a;
        else if(b[i]-'0'>a[i]-'0')return b;
        else continue;
    }
    return a;
}

//number of subarrays with xor less than  equal to k
ll subnum(string s,string k)
{
    int now=0;
    ll sum=0;
    forl(i,0,s.len)
    {
        if(s[i]=='1' && k[i]=='1')
        {

            if(trie[now].child[1]!=-1) sum+=trie[trie[now].child[1]].val;
            if(trie[now].child[0]==-1) return sum;
            else now=trie[now].child[0];

        }else if(s[i]=='0' && k[i]=='0')
        {
            if(trie[now].child[0]!=-1) now=trie[now].child[0];
            else return sum;

        }else if(s[i]=='0' && k[i]=='1')
        {
            if(trie[now].child[0]!=-1) sum+=trie[trie[now].child[0]].val;
            if(trie[now].child[1]==-1) return sum;
            else now=trie[now].child[1];

        }else if(s[i]=='1' && k[i]=='0'){
            
            if(trie[now].child[1]!=-1) now=trie[now].child[1];
            else return sum;

        }
    }
    sum+=trie[now].val;
    return sum;
   
}



int main()
{
    //maximum xor subarray o(n) 


    // int t;
    // cin>>t;
    // while(t--)
    // {
    // trie.clear();
    // initialise();
    // int n;
    // cin>>n;
    // ll arr[n];
    // forl(i,0,n) cin>>arr[i];
    // ll ps[n+1];
    // ps[0]=0;
    // forl(i,1,n+1) ps[i]=ps[i-1]^arr[i-1];
    // string sarr[n+1];
    // forl(i,0,n+1)
    // {
    //     sarr[i]=bitset<32>(ps[i]).to_string();
    // }
    // string out="";
    // forl(i,0,n+1)
    // {
    //     insert(sarr[i]);
    //     string fnl=maxxor(sarr[i]);
    //     out=maxi(out,fnl);
    // }
    // cout<<stoll(out,0,2)<<endl;


    //  }
    

    // subarrays with xor less than equal to k
    // int t;
    // cin>>t;
    // while(t--)
    // {
    //     initialise();
    //     int n;
    //     ll k;
    //     cin>>n>>k;
    //     k--;
    //     ll arr[n];
    //     forl(i,0,n) cin>>arr[i];
    //     ll ps[n+1];
    //     ps[0]=0;
    //     forl(i,1,n+1) ps[i]=(ps[i-1]^arr[i-1]);
    //     string sps[n+1];
    //     forl(i,0,n+1)
    //     {
    //         sps[i]=bitset<32>(ps[i]).to_string();
    //     }
    //     string ks=bitset<32>(k).to_string();
    //     ll tot=0;
    //     insert(sps[0]);
    //     forl(i,1,n+1)
    //     {
            
    //         insert(sps[i]);
            
    //     }
    //     cout<<tot<<endl;
    // }

   
    
}
