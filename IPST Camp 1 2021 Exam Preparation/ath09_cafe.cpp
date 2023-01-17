//       16/2/2564
#include<bits/stdc++.h>
using namespace std;
int T,V,u,v,cnt;
vector<int> edge[1005][7];
int dp[1005][3];
int dfs(int u,int par){
    if(dp[u][0]!=-1){
        int mx=max(dp[u][0],max(dp[u][1],dp[u][2]));
        if(mx==dp[u][0]) return 0;
        if(mx==dp[u][1]) return 1;
        return 2;
    }
    if(cnt++>1000) return 0;
    //printf("vst %d %d\n",u+1,par+1);
    int sum0=0,sum1=0,sum2=0,mxdiff=0,r; //sum if set to 0,1,2
    for(int i=0;i<edge[u][T].size();++i){
        int v=edge[u][T][i];
        if(v!=par){
            r=dfs(v,u);
            sum0+=max(dp[v][1],max(dp[v][0],dp[v][2]));
            sum1+=dp[v][0];
            sum2+=dp[v][0];
            if(mxdiff<dp[v][1]-dp[v][0]){
                mxdiff=dp[v][1]-dp[v][0];
            }
        }
    }
    dp[u][0]=sum0;
    dp[u][1]=sum1+mxdiff+1;
    dp[u][2]=sum2+1;
    if(dp[u][0]+1==dp[u][1]&&dp[u][2]+1==dp[u][1]&&dp[u][0]==dp[u][2]&&!(dp[u][0]%2)&&dp[u][1]%2) --dp[u][1];
    //printf("u%d (%d,%d,%d)\n",u+1,dp[u][0],dp[u][1],dp[u][2]);
    int mx=max(dp[u][0],max(dp[u][1],dp[u][2]));
    if(mx==dp[u][0]) return 0;
    if(mx==dp[u][1]) return 1;
    return 2;
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&V);
        for(int i=0;i<V-1;++i){
            scanf("%d %d",&u,&v);
            dp[i][0]=-1;
            dp[i][1]=-1;
            dp[i][2]=-1;
            edge[u-1][T].push_back(v-1);
            edge[v-1][T].push_back(u-1);
        }
        dp[V-1][0]=-1;
        dp[V-1][1]=-1;
        dp[V-1][2]=-1;
        dfs(0,-1);
        printf("%d\n",max(dp[0][0],max(dp[0][1],dp[0][2])));
    }
}