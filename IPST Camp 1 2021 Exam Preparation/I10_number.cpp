//                      12/1/2564
#include<bits/stdc++.h>
using namespace std;
int n,mx,mxd,cost[12];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=9;++i){
        scanf("%d",&cost[i]);
        if(n/cost[i]>mx||(n/cost[i]==mx&&cost[i]<=cost[mxd])){
            mx=n/cost[i];
            mxd=i;
        }
    }
    n-=(cost[mxd]*mx);
    vector<int> v(mx,mxd);
    //for(int i=0;i<mx;++i) printf("%d ",v[i]); printf(" %d \n",n);
    for(int i=0;i<mx;++i){
        for(int j=9;j>=v[i]+1;--j){
            if(n-cost[j]+cost[v[i]]>=0){
                n-=(cost[j]-cost[v[i]]);
                v[i]=j;
                //printf("*%d*\n",n);
                break;
            }
        }
        printf("%d",v[i]);
    }
}