//                      15/11/2563
#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int n;
vector<char> v;
char ch;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        cin>>ch;
        v.push_back(ch);
    }
    int i=0,j=1;
    while(1){
        //printf("(%d,%d)\n",i,j);
        if(v[i]==v[j]) dp[i][j]=1+dp[i+1][j-1];
        else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
        if(i==0&&j==n-1) break;
        ++i;
        ++j;
        if(j==n){
            j=(j-i)+1;
            i=0;
        }
    }
    //for(int i=0;i<n;++i)
    printf("%d",dp[0][n-1]);
}