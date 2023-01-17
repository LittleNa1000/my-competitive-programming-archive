#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
#define ff first
#define ss second
//or begin from destination -> start
bool vst[1048576][20];
int dp[1048576][20];
int happy[25][25],n;
int f(ii x){
    int idx=x.ff,u=x.ss;
    if(vst[idx][u]) return dp[idx][u];
    if(idx==(1<<(n-1))+1){
        vst[idx][u]=1;
        dp[idx][u]=happy[0][u];
         //printf("(%d, %d) %d\n",idx,u,dp[idx]);
        return dp[idx][u];
    }
    int mx=INT_MIN,uu;
    for(int i=1;i<n-1;++i){
        if((1<<i)&idx){
            if(mx<f({idx-(1<<i),i})+happy[i][u]){
                mx=f({idx-(1<<i),i})+happy[i][u];
            }
        }
        
    }
    vst[idx][u]=1;
    dp[idx][u]=mx;
     //printf("(%d, %d) %d\n",idx,u,dp[idx]);
    return dp[idx][u];
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            scanf("%d",&happy[i][j]);
        }
    }
    f({(1<<n)-1,n-1});
    printf("%d",dp[(1<<n)-1][n-1]);
}