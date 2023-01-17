//                      14/1/2564
#include<bits/stdc++.h>
using namespace std;
int n,ans,k,cost[2],tc;
int dp[11][2][205];
int main(){
    scanf("%d",&tc);
    for(int t=0;t<tc;++t){
        scanf("%d%d",&n,&k);
        for(int i=0;i<=2*k;++i){
            dp[t][0][i]=2e9;
            dp[t][1][i]=2e9;
        }
        for(int i=0;i<n;++i){
            scanf("%d%d",&cost[0],&cost[1]); //or cost[0] cost[1]
            if(i==0){
                dp[t][1][k-1]=cost[0];
                dp[t][1][k+1]=cost[1];
            }
            else{
                for(int j=0;j<=2*k;++j){
                    if(j-1>=0&&dp[t][0][j-1]>0) dp[t][1][j]=min(dp[t][1][j],dp[t][0][j-1]+cost[1]);
                    if(j+1<=2*k&&dp[t][0][j+1]>0) dp[t][1][j]=min(dp[t][1][j],dp[t][0][j+1]+cost[0]);
                }
            }
            for(int j=0;j<=2*k;++j){
                //printf("%d ",dp[t][1][j]);
                dp[t][0][j]=dp[t][1][j];
                dp[t][1][j]=2e9;
            }
            //printf("\n");
        }
        ans=2e9;
        for(int i=0;i<=2*k;++i) ans=min(ans,dp[t][0][i]);
        printf("%d\n",ans);
    }
    
}