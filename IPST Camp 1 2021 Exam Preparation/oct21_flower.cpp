//                      14/1/2564
#include<bits/stdc++.h>
using namespace std;
int W,n,tem;
int w[105],v[105],k[105],dp_v[105][105],dp_k[105][105];
int main(){
    scanf("%d%d",&W,&n);
    for(int i=1;i<=n;++i){
        scanf("%d%d%d",&w[i],&v[i],&tem);
        if(tem) k[i]=1;
        else k[i]=-1;
    }
    for(int i=1;i<=n;++i){ // i th Item
        for(int j=1;j<=W;++j){ // j th budget
            dp_v[i][j]=dp_v[i-1][j];
            dp_k[i][j]=dp_k[i-1][j];
            if(j>=w[i]&&abs(dp_k[i-1][j-w[i]]+k[i]<=4)){
                if(dp_v[i][j]<dp_v[i-1][j-w[i]]+v[i]){
                    dp_v[i][j]=dp_v[i-1][j-w[i]]+v[i];
                    dp_k[i][j]=dp_k[i-1][j-w[i]]+k[i];
                }
                else if(dp_v[i][j]==dp_v[i-1][j-w[i]]+v[i]&&abs(dp_k[i-1][j-w[i]]+k[i])<abs(dp_k[i][j])){
                    dp_v[i][j]=dp_v[i-1][j-w[i]]+v[i];
                    dp_k[i][j]=dp_k[i-1][j-w[i]]+k[i];
                }
            }
            //printf("(%d,%d) ",dp_v[i][j],dp_k[i][j]);
        }
        //printf("\n");
    }
    printf("%d",dp_v[n][W]);
}