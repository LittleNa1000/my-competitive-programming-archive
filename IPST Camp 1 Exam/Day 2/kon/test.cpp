#include<bits/stdc++.h>
using namespace std;
int n,dp[10000005]={0,0},x,y;
vector<int> v[1000002];
bool a[1000002];
int main(){
    freopen("out.txt","w",stdout);
    // a[9]=0;
    // a[30]=0;
    // a[1219]=0;
    // a[50220]=0;
    // a[124609]=0;
    a[508394]=1;//
    // a[649424]=0;
    // a[882660]=0;
    //a[945595]=1;//
    // a[1000000]=0;
    for(int j=2;j<=508394;++j){
        dp[j]=j+2;
        x=0;
        y=0;
        for(int i=2;i<=sqrt(j);++i){
            if(j%i==0){
                if(dp[j]>dp[i]+dp[j/i]){
                    x=i;
                    y=j/i;
                    dp[j]=dp[i]+dp[j/i];
                }
                //printf("%d %d %d %d %d\n",i,j/i,dp[i],dp[j/i],dp[j]);
            }
        }
        if(x==0&&y==0){
            v[j].push_back(j);
            continue;
        }
        else{
            for(int i=0;i<v[x].size();++i){
                v[j].push_back(v[x][i]);
            }
            for(int i=0;i<v[y].size();++i){
                v[j].push_back(v[y][i]);
            }  
        }
        
        //printf("%d %d %d %d\n",j,dp[j],x,y);
        //for(int i=0;i<v[j].size();++i) printf("%d ",v[j][i]); printf("\n");
        if(a[j]){
            printf("%d\n",j);
            for(int i=0;i<v[j].size();++i){
                printf("AC");
                //printf("*%d* ",v[j][i]);
                for(int k=0;k<v[j][i];++k){
                    printf("V");
                    
                }
            }
            printf("\n");
            // for(int i=0;i<v[254196].size();++i){
            //     printf("AC");
            //     printf("*%d* ",v[254196][i]);
            //     // for(int k=0;k<v[j][i];++k){
            //     //     printf("V");
                    
            //     // }
            // }
        }
    }
    //254197
}