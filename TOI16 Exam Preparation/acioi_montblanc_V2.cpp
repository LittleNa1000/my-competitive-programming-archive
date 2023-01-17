//                      18/10/2563
#include<bits/stdc++.h>
using namespace std;
int n,k,l,r,ans=INT_MAX,idx,cnt,day,m,gap=INT_MIN,reach;
int h[100002];
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;++i){
        scanf("%d",&h[i]);
        if(i>0) gap=max(gap,h[i]-h[i-1]);
    }
    l=max(gap,(h[n-1]/k)); // maybe better
    r=h[n-1];
    while(l<=r){
        m=(l+r)/2;
        cnt=0;
        for(idx=0;idx<n;++cnt){
            reach=m;
            if(cnt!=0) reach+=h[idx-1];
            while(idx<n&&h[idx]<=reach) ++idx;
        }
        //printf("%d %d %d",l,m,r);printf("cnt=%d\n",cnt);
        if(cnt<=k){
            if(ans>m){
                ans=m;
                day=cnt;
            }
            r=m-1;
        }
        else{
            l=m+1;
        }
    }
    printf("%d %d",ans,day);
}