//                  20/11/2563
#include<bits/stdc++.h>
using namespace std;
int k,sx,sy,sz,n,px,py,pz,pa,pb,pc;
int x[15],y[15],z[15],a[15],b[15],c[15];
long long int d,ans=LONG_LONG_MAX;
int main(){
    scanf("%d%d%d%d%d",&k,&sx,&sy,&sz,&n);
    int per[n];
    for(int i=0;i<n;++i){
        scanf("%d%d%d%d%d%d",&x[i],&y[i],&z[i],&a[i],&b[i],&c[i]);
        per[i]=i;
    }
    do{
        px=sx;
        py=sy;
        pz=sz;
        d=0;
        pa=0;
        pb=0;
        pc=0;
        for(int i=0;i<n;++i){
            d+=(px-x[per[i]])*(px-x[per[i]])+(py-y[per[i]])*(py-y[per[i]])+(pz-z[per[i]])*(pz-z[per[i]]);
            pa+=a[per[i]];
            pb+=b[per[i]];
            pc+=c[per[i]];
            px=x[per[i]];
            py=y[per[i]];
            pz=z[per[i]];
            if(pa>=k&&pb>=k&&pc>=k){
                ans=min(ans,d); 
                break;
            }
        }
    }while(next_permutation(per,per+n));
    printf("%lld",ans);
}