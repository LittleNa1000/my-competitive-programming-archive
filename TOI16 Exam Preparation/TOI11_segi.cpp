//                      20/11/2563
#include<bits/stdc++.h>
using namespace std;
int op[][3]={{2,1,0},{2,1,1},{1,2,1}};
int dp[260][260][5];
int n;
string str;
void segi(int l,int r){
    if(dp[l][r][3]) return ;
    dp[l][r][3]=1;
    if(l>r) return ;
    if(l==r){
        dp[l][r][str[l]-'0']=1;
        return ;
    }
    if(r-l==1){
        dp[l][r][op[str[l]-'0'][str[r]-'0']]=1; return ;
    }
    for(int k=l;k<r;++k){
        if(!dp[l][k][3]) segi(l,k);
        if(!dp[k+1][r][3]) segi(k+1,r);
        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                if(dp[l][k][i]&&dp[k+1][r][j]){
                    dp[l][r][op[i][j]]=1;
                }
            }
        }
    }
}
int main(){
    for(int tc=0;tc<20;tc++){
        scanf("%d",&n);
        cin>>str;
        for(int i=0;i<255;++i){
            for(int j=0;j<255;++j) for(int k=0;k<4;++k) dp[i][j][k]=0;
        }
        segi(0,n-1);
        if(dp[0][n-1][0]) printf("yes\n");
        else printf("no\n");
        //for(int i=0;i<n;++i) {for(int j=0;j<n;++j) printf("([%d,%d]%d,%d,%d) ",i+1,j+1,dp[i][j][0],dp[i][j][1],dp[i][j][2]); printf("\n");}
    }
}