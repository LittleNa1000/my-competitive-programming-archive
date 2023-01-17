//                      8/1/2564 or BS to find ans
#include<bits/stdc++.h>
using namespace std;
bool des(const int &a,const int &b){
    return a>b;
}
int n,ans,x[100012],y[100012];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&x[i]);
    }
    for(int i=0;i<n;++i){
        scanf("%d",&y[i]);
    }
    sort(x,x+n);
    sort(y,y+n,des);
    for(int i=0;i<n;++i){
        ans=max(ans,min(x[i],y[i]));
    }
    printf("%d",ans);
}