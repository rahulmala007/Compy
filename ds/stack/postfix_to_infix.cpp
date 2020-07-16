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


// we are dealing with only single bit operands but it can be extended to other operands

// all the operators we are considereing can be changed here
bool isOperator(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/') return true;
    else return false;
}
string toInfix(string postfix)
{
    stack<string>st;
    int i=0;
    while(i<postfix.len)
    {
        if(isOperator(postfix[i]))
        {
            string b=st.top();
            st.pop();
            string a=st.top();
            st.pop();
            if(postfix[i]=='+')
            {
                st.push("(" + a + "+" + b + ")");
            }else if(postfix[i]=='-')
            {
                st.push("(" + a + "-" + b + ")");

            }else if(postfix[i]=='*')
            {
                st.push("(" + a + "*" + b + ")");

            }else{
                st.push("(" + a + "/" + b + ")");

            }
        }else{
            string s="";
            s+=postfix[i];
            st.push(s);
        }
        i++;
    }
    return st.top();
}
int main()
{
    cout<<toInfix("231*+9-")<<endl;
}

