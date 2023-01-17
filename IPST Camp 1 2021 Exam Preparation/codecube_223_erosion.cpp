//      12/2/2564
#include<bits/stdc++.h>
using namespace std;
int n,m,str[7005][7005],cnt[7005],mn;
string in[7005];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;++i){
        cin>>in[i];
        // for(int j=0;j<m;++j){
        //     str[i][j]=in[i][j]-'0';
        // }
    }
    for(int i=n-1;i>=0;--i){
        for(int j=m-1;j>=0;--j){
            str[i][j]=in[i][j]-'0';
            if(str[i][j]){
                mn=min(str[i+1][j],min(str[i][j+1],str[i+1][j+1]));
                str[i][j]+=mn;
            }
            if(str[i][j]){
                ++cnt[str[i][j]];
            }
        }
    }
    // for(int i=0;i<n;++i){
    //     for(int j=0;j<m;++j){
    //         printf("%d ",str[i][j]);
    //     }
    //     printf("\n");
    // }
    for(int i=min(n,m);i>=1;--i){
        cnt[i]+=cnt[i+1];
    }
    for(int i=1;i<=min(n,m);++i){
        printf("%d\n",cnt[i]);
    }
}