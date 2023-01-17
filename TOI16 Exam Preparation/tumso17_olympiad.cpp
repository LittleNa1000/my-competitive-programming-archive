//                      23/10/2563
#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int arr[1005][1005],dp[1005][1005];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            scanf("%d",&arr[i][j]);
        }
    }
    for(int j=0;j<m;++j){
        for(int i=0;i<n;++i){
            dp[i][j]=arr[i][j];
            if(j==0) continue;
            if(i==0) dp[i][j]+=min(dp[i][j-1],dp[i+1][j-1]);
            else if(i==n-1) dp[i][j]+=min(dp[i][j-1],dp[i-1][j-1]);
            else dp[i][j]+=min(dp[i][j-1],min(dp[i-1][j-1],dp[i+1][j-1]));
        }
    }
    /*for(int i=0;i<n;++i){
        for(int j=0;j<m;++j) printf("%d ",dp[i][j]);
        printf("\n");
    }*/
    for(int i=0;i<n;++i){
        if(i==0) ans=min(dp[i][m-1],dp[i+1][m-1]);
        else if(i==n-1) ans=min(dp[i][m-1],dp[i-1][m-1]);
        else ans=min(dp[i][m-1],min(dp[i-1][m-1],dp[i+1][m-1]));
        printf("%d\n",ans);
    }
}