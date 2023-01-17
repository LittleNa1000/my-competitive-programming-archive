//      12/2/2564
#include<bits/stdc++.h>
using namespace std;
int dp[1005]={0,1,2,5};
unsigned long long pascal[2][1005]={{1,3,3,1},{}};
int idx;
int main(){
    for(int i=4;i<=100;++i){
        for(int j=0;j<i;++j){
            dp[i]+=(dp[j]*pascal[idx][j])%10001;
        }
        dp[i]%=10001;
        pascal[!idx][0]=1;
        pascal[!idx][i]=1;
        for(int j=1;j<i;++j){
            pascal[!idx][j]=pascal[idx][j]+pascal[idx][j-1];
        }
        for(int j=0;j<=i;++j) printf("%llu ",pascal[!idx][j]); printf("\n");
        idx=!idx;
    }
    for(int i=4;i<=100;++i){
        printf("%d %d\n",i,dp[i]);
    }
}