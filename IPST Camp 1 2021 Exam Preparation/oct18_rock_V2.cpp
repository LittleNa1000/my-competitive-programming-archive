//      12/2/2564
#include<bits/stdc++.h>
using namespace std;
bool assign[55][55];
int dp[55][55],n,num[55];
int f(int l,int r){
    if(l>r) return 0;
    if(assign[l][r]||l==r) return dp[l][r];
    if((r-l+1)%2==0){
        dp[l][r]=max(num[l]+f(l+1,r),num[r]+f(l,r-1));
    }
    else{
        dp[l][r]=max(f(l+1,r),f(l,r-1));
    }
    assign[l][r]=1;
    return dp[l][r];
}
int main(){
    scanf("%d",&n);
    n*=2;
    for(int i=0;i<n;++i){
        scanf("%d",&num[i]);
    }
    printf("%d",f(0,n-1));
}