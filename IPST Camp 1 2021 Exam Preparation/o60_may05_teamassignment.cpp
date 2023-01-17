//                      16/1/2564
#include<bits/stdc++.h>
using namespace std;
int segt[400005];
int tg,val,tem,n,s,e,lb,ub,ans=-1,idxL,idxM,idxR,l,m,r,add;
bool succ;
vector<int> v;
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
    scanf("%d%d%d",&n,&lb,&ub);
    for(int i=0;i<n;++i){
        scanf("%d",&tem);
        v.push_back(tem);
        tg=i;
        val=tem;
        update(0,n-1,0);
    }
    sort(v.begin(),v.end());
    idxL=0;
    idxR=n-1;
    while(idxL<=idxR){
        idxM=(idxL+idxR)/2;
        succ=1;
        for(int i=0;i<n;){
            if(i+lb+lb-2>=n){
                if(n-1-i>=ub){
                    succ=0;
                    break;
                }
                else{
                    l=n-1-i;
                    r=n-1-i;
                }
            }
            else{
                l=lb-1;
                r=ub-1;
            }
            add=1e9;
            while(l<=r){
                m=(l+r)/2;
                if(i+m>=n) r=m-1;
                else{
                    s=i;
                    e=i+m;
                    if(query(0,n-1,0)>=v[idxM]){
                        add=min(add,m);//or max
                        r=m-1;
                    }
                    else{
                        l=m+1;
                    }
                }
            }
            //printf("(%d,%d,%d) %d add%d\n",idxL,idxM,idxR,v[idxM],add);
            if(add==1e9){
                succ=0;
                break;
            }
            i+=add+1;
            
        }
        //printf("(%d,%d,%d) %d s=%d\n",idxL,idxM,idxR,v[idxM],succ);
        if(succ){
            ans=max(ans,v[idxM]);
            idxL=idxM+1;
        }
        else idxR=idxM-1;
    }
    printf("%d",ans);
}