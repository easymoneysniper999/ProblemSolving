#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M  ((long long)(((long long)(1e9))+7))

ll solve()
{
   ll n;
   cin>>n;
   ll con[61];
   memset(con, 0, sizeof(con));
   for(int i=0;i<n;i++)
   {
    ll temp;
    cin>>temp;
    ll pw=1;
    for(int j=0;j<61;j++)
    {
        con[j]+=(temp&pw?1:0);
        pw*=2LL;
    }
   }
   ll pw=1;
   ll ans=0;
   for(int i=0;i<61;i++)
   {
    ans=(ans+(((con[i]*(n-con[i]))%M)*pw)%M)%M;
    pw*=2LL;
    pw%=M;
   }
   cout<<ans<<endl;
   return 0;
}

int main()
{
    solve();
    return 0;
}
