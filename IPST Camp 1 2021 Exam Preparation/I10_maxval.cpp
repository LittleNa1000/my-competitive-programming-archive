//                      5/1/2564
#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000012],ans,sum;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<k;++i){
        sum+=a[i];
        //printf("%d\n",sum);
    }
    ans=sum;
    for(int i=k;i<n;++i){
        sum+=a[i]-a[i-k];
        ans=max(ans,sum);
    }
    printf("%d",ans);
}