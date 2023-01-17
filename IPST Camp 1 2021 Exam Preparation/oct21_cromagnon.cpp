//                      13/1/2564
#include<bits/stdc++.h>
using namespace std;
bool visited[105][105];
int dp[105][105][25],op[25][25],a[105];
int n,m;
void f(int l,int r){
    if(l>r||visited[l][r]) return ;
    if(l==r){
        dp[l][r][a[l]]++;
    }
    else if(l+1==r){
        dp[l][r][op[a[l]][a[r]]]++;
    }
    else{
        for(int k=l;k<r;++k){
            if(!visited[l][k]) f(l,k);
            if(!visited[k+1][r]) f(k+1,r);
            for(int i=0;i<m;++i){
                for(int j=0;j<m;++j){
                    dp[l][r][op[i][j]]+=(dp[l][k][i]*dp[k+1][r][j])%2009;
                }
            }
        }
    }
    //for(int i=0;i<m;++i) printf("%d ",dp[l][r][i]); printf("(%d,%d)\n",l,r);
    for(int i=0;i<m;++i) dp[l][r][i]%=2009;
    visited[l][r]=1;
    return ;
}
int main(){
    scanf("%d",&m);
    for(int i=0;i<m;++i){
        for(int j=0;j<m;++j){
            scanf("%d",&op[i][j]);
        }
    }
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    f(0,n-1);
    for(int i=0;i<m;++i) printf("%d\n",dp[0][n-1][i]%2009);
}