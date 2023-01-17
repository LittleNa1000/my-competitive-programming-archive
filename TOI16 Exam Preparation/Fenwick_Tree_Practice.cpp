//                      22/11/2563 Fenwick Tree Practice
#include<bits/stdc++.h>
using namespace std;
int fen[100005];
int n,q;
char ch;
void upd(int idx,int val){
    while(idx<=n){
        fen[idx]+=val;
        idx=idx+(idx & -idx);
    }
}
int sum(int idx){
    int res=0;
    while(idx>0){
        res+=fen[idx];
        idx=idx-(idx&-idx);
    }
    return res;
}
int main(){
    int l,r,idx,val,tem,x;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;++i){
        scanf("%d",&tem);
        upd(i,tem);
    }
    while(q--){
        cin>>ch;
        if(ch=='S'){
            scanf("%d",&x);
            printf("Sum = %d\n",sum(x));
        }
        else{
            scanf("%d %d",&idx,&val);
            upd(idx,val);
            for(int i=0;i<=n;++i) printf("%d ",fen[i]); printf("\n");
        }
    }
}