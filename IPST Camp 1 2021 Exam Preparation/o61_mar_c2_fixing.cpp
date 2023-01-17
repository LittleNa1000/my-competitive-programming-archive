//				9/1/2564
#include<bits/stdc++.h>
using namespace std;
int broke[100012],gap[100012],qsum[100012];
int n,m,k;
int main(){
	scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<m;++i){
        scanf("%d",&broke[i]); //or broke[i]=1;
        if(i>0) gap[i-1]=broke[i]-broke[i-1]-1;
    }
    sort(gap,gap+m-1);
    for(int i=0;i<m-1;++i){
        if(!i) qsum[i]=gap[i];
        else qsum[i]=qsum[i-1]+gap[i];
        //printf("%d\n",qsum[i]);
    }
    if(k>=m) printf("0");
    else printf("%d",qsum[m-k-1]);
}
