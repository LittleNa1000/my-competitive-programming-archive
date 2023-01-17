//       16/2/2564 can do better
#include<bits/stdc++.h>
using namespace std;
int n,m,T,arr[505][505],ans;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&m);
        ans=INT_MAX;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                scanf("%d",&arr[i][j]);
            }
        }
        for(int i=1;i<n;++i){
            for(int j=0;j<m;++j){
                if(j==0) arr[i][j]+=min(arr[i-1][j],arr[i-1][j+1]);
                else if(j+1==m) arr[i][j]+=min(arr[i-1][j],arr[i-1][j-1]);
                else arr[i][j]+=min(arr[i-1][j],min(arr[i-1][j-1],arr[i-1][j+1]));
                //printf("%d ",arr[i][j]);
                if(i+1==n) ans=min(ans,arr[i][j]);
            }
            //printf("\n");
        }
        printf("%d\n",ans);
    }
}