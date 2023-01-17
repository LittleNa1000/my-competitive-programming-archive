//                  5/5/2564
// Fenwick Tree
#include<bits/stdc++.h>
using namespace std;
int fen[1000005],n,m;
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
int T,val,idx,idx1,idx2;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;++i){
        scanf("%d",&T);
        if(T==1){
            scanf("%d %d",&val,&idx);
            upd(idx,val);
        }
        else{
            scanf("%d %d",&idx1,&idx2);
            printf("%d\n",sum(idx2)-sum(idx1-1));
        }
    }
}