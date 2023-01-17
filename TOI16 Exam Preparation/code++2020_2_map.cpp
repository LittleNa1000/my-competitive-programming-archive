//                  18/10/2563
#include<bits/stdc++.h>
using namespace std;
int t,n,k,tem,ans,sum,x,y;
int main(){
    scanf("%d",&t);
    for(int g=0;g<t;++g){
        ans=0;
        unsigned short qsum[501][501];
        for(int i=0;i<501;++i) qsum[i][0]=0;
        for(int i=0;i<501;++i) qsum[0][i]=0;
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                scanf("%hu",&tem);
                qsum[i][j]=tem+qsum[i-1][j]+qsum[i][j-1]-qsum[i-1][j-1];
            }
        }
        for(int i=1;i<=n-k+1;++i){
            for(int j=1;j<=n-k+1;++j){
                sum=qsum[i+k-1][j+k-1]-qsum[i+k-1][j-1]-qsum[i-1][j+k-1]+qsum[i-1][j-1];
                //printf("*(%d,%d)%d,%d* ",j-1,i-1,sum,ans);
                if(sum>ans){
                    ans=sum;
                    x=j-1;
                    y=i-1;
                }
                else if(sum==ans){
                    if(i+j-2<x+y){
                        x=j-1;
                        y=i-1;
                    }
                    else if(i+j-2==x+y){
                        if(j-1>x){
                            x=j-1;
                            y=i-1;
                        }
                    }
                }
            }
            //printf("\n");
        }
        printf("%d %d\n",x,y);
    }
}