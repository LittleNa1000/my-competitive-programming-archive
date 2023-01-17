//                      22/10/2563
#include<bits/stdc++.h>
using namespace std;
int segt[1048580];
int tg,val,tem,tem2,n,q,s,e;
char ch;
void update(int l,int r,int idx){
    if(l==tg&&r==tg){
        segt[idx]=val;
        return ;
    }
    int m=(l+r)/2;
    if(tg>m){
        update(m+1,r,(idx*2)+2);
    }
    else{
        update(l,m,(idx*2)+1);
    }
    segt[idx]=max(segt[(idx*2)+1],segt[(idx*2)+2]);
}
int query(int l,int r,int idx){
    //printf("(%d %d) %d*\n",l,r,idx);
    if(s<=l&&r<=e){ //s<=l&&e>=r
        return segt[idx];
    }
    if(l>e||r<s||l>r){
        return INT_MIN;
    }
    int m=(l+r)/2;
    return max(query(l,m,(idx*2)+1),query(m+1,r,(idx*2)+2));
}
int main(){
    scanf("%d %d",&n,&q);
    while(q--){
        cin>>ch;
        if(ch=='U'){
            //scanf("%d %d",&tg,&val);
            cin>>tg>>val;
            --tg;
            update(0,n-1,0);
        }
        else{
            //scanf("%d %d",&s,&e);
            cin>>tem>>tem2;
            --tem;
            --tem2;
            s=tem;
            e=tem2;
            printf("%d\n",query(0,n-1,0));
        }
        //for(int i=0;i<4*n;++i) printf("%d ",segt[i]);
        //printf("\n");
    }
}