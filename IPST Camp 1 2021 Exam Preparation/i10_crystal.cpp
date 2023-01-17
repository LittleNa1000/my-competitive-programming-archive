//      12/2/2564
#include<bits/stdc++.h>
using namespace std;
#define MOD 10001
int dp[1005]={1,1,2,5};
int main(){
    for(int i=4;i<=1000;++i){
        for(int j=0;j<i;++j){
            dp[i]+=(dp[j]*dp[i-1-j]);
            dp[i]%=MOD;
        }
        //printf("%d\n",dp[i]);
    }
    int n;
    scanf("%d",&n);
    printf("%d",dp[n]);
}