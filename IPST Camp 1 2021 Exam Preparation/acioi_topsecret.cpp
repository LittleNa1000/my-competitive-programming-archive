//                      14/1/2564
#include<bits/stdc++.h>
using namespace std;
int n,ans,k,cost[100005][3];
int dp[2][205];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i){
        scanf("%d%d",&cost[i][0],&cost[i][1]); //or cost[0] cost[1]
    }
    for(int i=0;i<n;++i){
        if(i==0){
            dp[1][k-1]=cost[i][0];
            dp[1][k+1]=cost[i][1];
        }
        else{
            for(int j=0;j<=2*k;++j){
                if(j-1>=0&&dp[0][j-1]>0) dp[1][j]=max(dp[1][j],dp[0][j-1]+cost[i][1]);
                if(j+1<=2*k&&dp[0][j+1]>0) dp[1][j]=max(dp[1][j],dp[0][j+1]+cost[i][0]);
            }
        }
        for(int j=0;j<=2*k;++j){
            //printf("%d ",dp[1][j]);
            dp[0][j]=dp[1][j];
            dp[1][j]=0;
        }
        //printf("\n");
    }
    ans=0;
    for(int i=0;i<=2*k;++i) ans=max(ans,dp[0][i]);
    printf("%d",ans);
}