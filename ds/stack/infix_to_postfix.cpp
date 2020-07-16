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

bool isOperator(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/') return true;
    else return false;
}

int precedence(char c) 
{ 
    if(c == '^') return 3; 
    else if(c == '*' || c == '/') return 2; 
    else if(c == '+' || c == '-') return 1; 
    else return -1; 
}
string toPostfix(string infix)
{
   int i=0;
    stack<char>op;
    stack<string>postfix;
    while(i<infix.len)
    {
        if(infix[i]=='(')
        {
            op.push(infix[i]);
        }else if (infix[i]==')')
        {
            while(op.top()!='(')
            {
                char oper=op.top();
                string b=postfix.top();
                postfix.pop();
                string a=postfix.top();
                postfix.pop();
                postfix.push(a+b+oper);
                op.pop();
            }
            op.pop();
        }else if(isOperator(infix[i]))
        {
            while(!op.empty() && precedence(op.top())>=precedence(infix[i]))
            {
                char oper=op.top();
                string b=postfix.top();
                postfix.pop();
                string a=postfix.top();
                postfix.pop();
                postfix.push(a+b+oper);
                op.pop();
            }
            op.push(infix[i]);
        }else{
            string s="";
            s+=infix[i];
            postfix.push(s);
        }


        i++;
    }
    return postfix.top();
}
int value(string infix)
{
    int i=0;
    stack<char>op;
    stack<int>val;
    while(i<infix.len)
    {
        if(infix[i]=='(')
        {
            op.push(infix[i]);
        }else if (infix[i]==')')
        {
            while(op.top()!='(')
            {
                char oper=op.top();
                int b=val.top();
                val.pop();
                int a=val.top();
                val.pop();
                if(oper=='+')
                {
                    val.push(a+b);
                }else if(oper=='-')
                {
                    val.push(a-b);

                }else if(oper=='*')
                {
                    val.push(a*b);

                }else{
                    val.push(a/b);

                }
                op.pop();
            }
            op.pop();
        }else if(isOperator(infix[i]))
        {
            while(!op.empty() && precedence(op.top())>=precedence(infix[i]))
            {
                char oper=op.top();
                int b=val.top();
                val.pop();
                int a=val.top();
                val.pop();
                if(oper=='+')
                {
                    val.push(a+b);
                }else if(oper=='-')
                {
                    val.push(a-b);

                }else if(oper=='*')
                {
                    val.push(a*b);

                }else{
                    val.push(a/b);

                }
                op.pop();
            }
            op.push(infix[i]);
        }else{
            val.push(infix[i]-'0');
        }


        i++;
    }
    return val.top();
}
int main()
{
     cout<<toPostfix("((2+(3*1))-9)")<<endl;
}

