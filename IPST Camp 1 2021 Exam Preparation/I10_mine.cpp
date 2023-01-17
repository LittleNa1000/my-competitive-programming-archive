//      21/2/2564
#include<bits/stdc++.h>
using namespace std;
int n,K,t,ans,qsum[1005][1005][3],dp[1005][1005][3],i2,j2;
int y[]={-1,-1,0,1,1,1,0,-1,0};
int x[]={0,1,1,1,0,-1,-1,-1,0};
int main(){
    scanf("%d %d",&n,&K);
    for(int k=0;k<3;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                scanf("%d",&t);
                qsum[i][j][k]=qsum[i-1][j][k]+qsum[i][j-1][k]-qsum[i-1][j-1][k]+t;
            }
        }        
    }
    for(int k=2;k>=0;--k){
        for(int i=K;i<=n;++i){
            for(int j=K;j<=n;++j){
                dp[i][j][k]+=qsum[i][j][k]-qsum[i-K][j][k]-qsum[i][j-K][k]+qsum[i-K][j-K][k];
                if(k>0){
                    for(int a=0;a<9;++a){
                        i2=i+y[a];
                        j2=j+x[a];
                        dp[i2][j2][k-1]=max(dp[i2][j2][k-1],dp[i][j][k]);
                    }                    
                }
                else{   
                    ans=max(ans,dp[i][j][k]);
                }
            }
        }
    }
    // for(int k=0;k<3;++k){
    //     for(int i=K;i<=n;++i){
    //         for(int j=K;j<=n;++j){
    //             printf("%d ",qsum[i][j][k]);
    //         }
    //         printf("\n");
    //     }        
    //     printf("\n");
    // }
    // for(int k=0;k<3;++k){
    //     for(int i=K;i<=n;++i){
    //         for(int j=K;j<=n;++j){
    //             printf("%d ",dp[i][j][k]);
    //         }
    //         printf("\n");
    //     }        
    //     printf("\n");
    // }
    printf("%d",ans);
}