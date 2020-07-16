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
const ll mod=1e9+7;

/*              DIGIT DP Tutorials 
1)https://codeforces.com/blog/entry/53960
2)https://codeforces.com/blog/entry/8221

this problem:
we will go on constructing the favourable strings followiing the condition that number <=k
1)dp[d][2]  where in dp[i][j]  i represents (sum till now )mod d  and j=1 means number is smaller already and if not j=0
2)we will use push dp and iterate over all the digits at current position

Case1: if number is already smaller:
Then we can place any digit at position i
dp[(sum+digit) mod d][0]=(dp[(sum+digit)mod d] [0] + dp[(sum)][1])

Case 2: number is not smaller
Subcase 1) if we put a smaller number than s[i]-'0'
------then the number formed will become smaller now so we have to push to that dp p[(sum+digit) mod d][1]=(dp[(sum+digit)mod d] [1] + dp[(sum)][0])
Subcase 2) if we put a number equal to s[i]-'0'
------then the number formed will not be smaller now so we have to push to that dp p[(sum+digit) mod d][0]=(dp[(sum+digit)mod d] [0] + dp[(sum)][0])
Subcase 3) if we put a greater equal to s[i]-'0'
------ this cannot be done as the formed number string will become larger than the given string 

this dp calculates answer for range [0...K]
but 0 will divisible byb every number
so answer is dp[0][1]+dp[0][0]-1  ....... 1)dp[0][1]---include k ,2)dp[0][0]--- include [0..k-1] ,3)  -1------ remove [0]
                                          
*/
int main()
{
   string s;
   cin>>s;
   int d;
   cin>>d;
   vector<vector<ll>>dp(d,vector<ll>(2));
   int n=s.len;
   dp[0][0]=1;
   forl(i,0,n)
   {
       vector<vector<ll>>newdp(d,vector<ll>(2));
       forl(j,0,d)
       {
           forl(k,0,2)
           {
               forl(digit,0,10)
               {
                   if(k==0 && digit>s[i]-'0') break;
                   if(k==1)newdp[(j+digit)%d][k]=(newdp[(j+digit)%d][k]+dp[j][k])%mod;
                   else 
                   {
                       if(digit<s[i]-'0')
                       {
                            newdp[(j+digit)%d][1]=(newdp[(j+digit)%d][1]+dp[j][k])%mod; 
                       }else{
                           newdp[(j+digit)%d][0]=(newdp[(j+digit)%d][0]+dp[j][k])%mod; 
                       }
                   }
               }
           }
       }
       dp=newdp;
   }    
   cout<<(dp[0][0]+dp[0][1]+mod-1)%mod<<endl;

}