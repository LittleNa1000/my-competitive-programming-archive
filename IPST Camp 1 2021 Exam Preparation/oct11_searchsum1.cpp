//                      7/1/2564
#include<bits/stdc++.h>
using namespace std;
int n,k,tem,qsum[100012];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i){
       scanf("%d",&tem);
       if(i!=0) qsum[i]=qsum[i-1]+tem; 
       else qsum[i]=tem;
    }
    for(int i=0;i<k;++i){
        scanf("%d",&tem);
        printf("%d\n",upper_bound(qsum,qsum+n,tem)-qsum);
    }
}