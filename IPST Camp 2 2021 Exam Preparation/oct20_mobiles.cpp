//              5/5/2564
#include<bits/stdc++.h>
using namespace std;
int T,n,a,b,c,d,k;
int seg[10000005];
void update(int idx,int i1,int j1,int i2,int j2){
    if(i1>i2||j1>j2) return ;
    int i_m=(i1+i2)/2,j_m=(j1+j2)/2;
    //printf("upd %d (%d %d) (%d %d)\n",idx,i1,j1,i2,j2);
    if(i1==i2&&j1==j2){
        seg[idx]+=k;
        return ;
    }
    if(a>i_m){
        if(b>j_m){
            //Q4
            update((idx*4)+4,i_m+1,j_m+1,i2,j2);
        }
        else{
            //Q3
            update((idx*4)+3,i_m+1,j1,i2,j_m);
        }
    }
    else{
        if(b>j_m){
            //Q1
            update((idx*4)+1,i1,j_m+1,i_m,j2);
        }
        else{
            //Q2
            update((idx*4)+2,i1,j1,i_m,j_m);
        }
    }
    seg[idx]=seg[(idx*4)+1]+seg[(idx*4)+2]+seg[(idx*4)+3]+seg[(idx*4)+4];
}
int sum(int idx,int i1,int j1,int i2,int j2){
    if(i1>i2||j1>j2) return 0;
    //printf("sum %d (%d %d) (%d %d)\n",idx,i1,j1,i2,j2);
    if((c<i1||d<j1)||(i2<a||j2<b)){
        return 0;
    }
    else if((a<=i1&&b<=j1)&&(i2<=c&&j2<=d)){
        return seg[idx];
    }
    else{
        int i_m=(i1+i2)/2,j_m=(j1+j2)/2;
        return sum((idx*4)+1,i1,j_m+1,i_m,j2)+
               sum((idx*4)+2,i1,j1,i_m,j_m)+
               sum((idx*4)+3,i_m+1,j1,i2,j_m)+
               sum((idx*4)+4,i_m+1,j_m+1,i2,j2);
    }
}
int main(){
    while(1){
        scanf("%d",&T);
        if(!T){
            scanf("%d",&n);
        }
        else if(T==1){
            scanf("%d %d %d",&a,&b,&k);
            update(0,0,0,n-1,n-1);
        }
        else if(T==2){
            scanf("%d %d %d %d",&a,&b,&c,&d);
            printf("%d\n",sum(0,0,0,n-1,n-1));
        }
        else return 0;
    }
}