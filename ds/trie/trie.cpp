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
//this represents each node of a trie
struct node{
    int val;
    int child[26];
    node()
    {  
        val=0;
        memset(child,-1,sizeof(child));
    }
};
vector<node>trie; //trie as a vector

//initialising the first node as null
void initilaise()
{
    node nullnode;
    nullnode.val=-1;
    trie.pb(nullnode);
}

//inserting a word in a trie
void insert_word(string s)
{
    int now=0;
    for(int i=0;i<s.len;i++)
    {
        int index=s[i]-'a';
        node newnode;
        if(trie[now].child[index]!=-1)trie[trie[now].child[index]].val++;
        else 
        {
            newnode.val++;
            trie[now].child[index]=trie.size();
            trie.push_back(newnode);
        }
        now=trie[now].child[index];    
    }
}

//check if a string is present in a trie
bool check_string(string s)
{
    node now=trie[0];
    forl(i,0,s.len)
    {
        if(now.child[s[i]-'a']!=-1) now=trie[now.child[s[i]-'a']];
        else return false;
    }
    return true;
}
int main()
{
    initilaise();
    insert_word("rahul");
    insert_word("mala");
    insert_word("rahux");
    insert_word("mat");
    cout<<check_string("rahul")<<endl;
    cout<<check_string("rahil")<<endl;
    cout<<check_string("mat")<<endl;
    cout<<check_string("mala")<<endl;
   
}
