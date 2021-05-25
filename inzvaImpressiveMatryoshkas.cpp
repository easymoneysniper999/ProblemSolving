#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M  ((long long)(((long long)(1e9))+7))

ll solve(int n, int k)
{
    vector<vector<ll> > dp(2, vector<ll>(k+1));

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            if(i==1)
            {
                if(j==0)
                {
                    dp[i%2][j]=1;
                }
                else
                {
                    dp[i%2][j]=0;
                }
                continue;
            }
            if(j==0)
            {
                dp[i%2][j]=1;
                continue;
            }
            dp[i%2][j]=dp[i%2][j-1]%M;
            dp[i%2][j]=(dp[i%2][j]+dp[1-(i%2)][j])%M;
            dp[i%2][j]=(dp[i%2][j]+M-((max(j-(i-1),0)==0)?0:dp[1-i%2][max(j-(i-1),0)-1]))%M;
        }
    }
    return dp[n%2][k];
}

int main()
{
    int N,K;
    cin>>N>>K;
    cout<<solve(N, K);
    return 0;
}
