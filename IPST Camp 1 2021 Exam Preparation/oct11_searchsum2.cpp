//                      7/1/2564
#include<bits/stdc++.h>
using namespace std;
int n,k,tem,qsum[1012],mnprice[1012];//ll
int sum(int l,int r){
    if(l==0) return qsum[r];
    return qsum[r]-qsum[l-1];
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i){
       scanf("%d",&tem);
       mnprice[i]=INT_MAX;
       if(i!=0) qsum[i]=qsum[i-1]+tem; 
       else qsum[i]=tem;
    }
    for(int i=0;i<n;++i){
        for(int j=i;j<n;++j){
            mnprice[j-i]=min(mnprice[j-i],sum(i,j));
        }
    }
    for(int i=0;i<k;++i){
        scanf("%d",&tem);
        printf("%d\n",upper_bound(mnprice,mnprice+n,tem)-mnprice);
    }
}