//                      5/1/2564
#include<bits/stdc++.h>
using namespace std;
int rp[5012],x,y,n,k,mx;
int main(){
    scanf("%d%d%d",&x,&y,&n);
    for(int i=0;i<n;++i){
        scanf("%d",&k);
        if(k>=y&&k<=x+y){
            rp[k]++;
            mx=max(mx,rp[k]);
        }
    }
    printf("%d",mx);
}