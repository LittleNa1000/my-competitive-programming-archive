//              4/5/2564
#include<bits/stdc++.h>
using namespace std;
struct N{
    int add,mx,itv,left,right;
};
N seg[10000005];
int n,m,a,b,k;
void build(int idx,int l,int r){
    if(l>r) return ;
    seg[idx].itv=1;
    seg[idx].left=l;
    seg[idx].right=r;
    int m=(l+r)/2;
    if(l==r) return ;
    build((idx*2)+1,l,m);
    build((idx*2)+2,m+1,r);
}
void update(int idx,int l,int r){
    if(l>r) return ;
    if(l>b||r<a){
        // do nothing
    }
    else if(l>=a&&r<=b){
        seg[idx].mx+=k;
        seg[idx].add+=k;
    }
    else{
        int m=(l+r)/2;
        update((idx*2)+1,l,m);
        update((idx*2)+2,m+1,r);
        // Merge Answer
        int L=(idx*2)+1,R=(idx*2)+2;
        if(seg[L].mx>seg[R].mx){
            seg[idx].mx=seg[L].mx;
            seg[idx].itv=seg[L].itv;
            seg[idx].left=seg[L].left;
            seg[idx].right=seg[L].right;
        }
        else if(seg[R].mx>seg[L].mx){
            seg[idx].mx=seg[R].mx;
            seg[idx].itv=seg[R].itv;
            seg[idx].left=seg[R].left;
            seg[idx].right=seg[R].right;
        }
        else{
            seg[idx].mx=seg[L].mx;
            seg[idx].itv=seg[L].itv+seg[R].itv;
            seg[idx].left=seg[L].left;
            seg[idx].right=seg[R].right;
            if(seg[L].right+1==seg[R].left) --seg[idx].itv;
        }
        seg[idx].mx+=seg[idx].add;
    }
    return ;
}
void display(int idx,int l,int r){
    if(l>r) return ;
    printf("idx = %d l,r = (%d,%d) seg = (%d,%d,%d,%d,%d)\n",idx,l,r,seg[idx].add,seg[idx].mx,seg[idx].itv,seg[idx].left,seg[idx].right);
    if(l==r) return ;
    int m=(l+r)/2;
    display((idx*2)+1,l,m);
    display((idx*2)+2,m+1,r);
}
int main(){
    scanf("%d %d",&n,&m);
    build(0,1,n);
    for(int z=0;z<m;++z){
        scanf("%d %d %d",&a,&b,&k);
        update(0,1,n);
        //display(0,1,n);
        printf("%d %d\n",seg[0].mx,seg[0].itv); 
    }
}