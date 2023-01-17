//                  15/11/2563
#include<bits/stdc++.h>
using namespace std;
int n;
char ch;
vector<char> v;
int dp[1001][1001];
int f(int l,int r){
    if(l>=r) return dp[l][r]=0;
    if(dp[l][r]!=-1) return dp[l][r];
    printf("(%d,%d)\n",l,r);
    if(v[l]==v[r]) dp[l][r]=1+f(l+1,r-1);
    for(int i=l;i<r;++i){
        dp[l][r]=max(dp[l][r],f(l,i)+f(i+1,r));
    }
    return dp[l][r];
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        cin>>ch;
        v.push_back(ch);
    }
    for(int i=0;i<n;++i) for(int j=0;j<n;++j) dp[i][j]=-1;
    printf("%d",f(0,n-1));
}