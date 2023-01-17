//      26/2/2564
#include<bits/stdc++.h>
using namespace std;
double seg[1000005];
int k,Q,n,a,b;
double x,y,z;
void ins(int L,double val,int l,int r,int idx){
    if(l==r&&L==l){
        seg[idx]=val;
        return ;
    }
    int m=(l+r)/2;
    if(m<L){
        ins(L,val,m+1,r,(idx*2)+2);
    }
    else ins(L,val,l,m,(idx*2)+1);
    seg[idx]=seg[(idx*2)+1]+seg[(idx*2)+2];
}
double query(int L,int R,int l,int r,int idx){
    if(l>R||r<L){
        return 0;
    }
    if(L<=l&&R>=r){
        return seg[idx];
    }
    int m=(l+r)/2;
    return query(L,R,l,m,(idx*2)+1)+query(L,R,m+1,r,(idx*2)+2);
}
double sum(int x){
    if(x<0) return 0;
    return ((x)*(x+1)*((2*x)+1))/6;
}
int main(){
    scanf("%d %d",&n,&Q);
    for(int i=0;i<n;++i){
        ins(i,i*i,0,n-1,0);
    }
    while(Q--){
        scanf("%d %d %d",&k,&a,&b);
        if(k){
            x=query(a,b,0,n-1,0);
            y=sum(b);
            z=sum(a-1);
            //printf("1 x%lld y%lld z%lld\n",x,y,z);
            if(x!=y-z){
                printf("NO\n");
            }
            else printf("YES\n");
        }
        else{
            x=query(a,a,0,n-1,0);
            y=query(b,b,0,n-1,0);
            //printf("0 x%lld y%lld\n",x,y);
            ins(a,y,0,n-1,0);
            ins(b,x,0,n-1,0);
        }
    }
}