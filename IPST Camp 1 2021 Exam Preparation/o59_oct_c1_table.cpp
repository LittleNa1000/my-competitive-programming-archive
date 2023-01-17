//      21/2/2564 can do better (k=4 in O(1))
#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> ii;
ii seg[305][100005]; // may increase later
ii tag[305],x,y,z1,z2;
long long r,c,Q,age,ans,mn,k;
void upd(long long num,long long idx,long long val,long long l,long long r,long long cur){
    if(l==r&&l==idx){
        seg[num][cur]={val,age};
        return ;
    }
    if(l>r) return ;
    long long m=(l+r)/2;
    if(m>=idx){
        upd(num,idx,val,l,m,(cur*2)+1);
        x=seg[num][(cur*2)+1];
        z1=seg[num][(cur*2)+2];
    }
    else{
        upd(num,idx,val,m+1,r,(cur*2)+2);
        x=seg[num][(cur*2)+2];
        z1=seg[num][(cur*2)+1];
    }
    z2=tag[num];
    if(z2.second>z1.second){
        y=z2;
    }
    else y=z1;
    seg[num][cur]={min(x.first,y.first),max(x.second,y.second)};
}
ii getnum(long long num,long long idx,long long l,long long r,long long cur){
    if(l==r&&l==idx){
        return seg[num][cur];
    }
    if(l>r) return {LONG_LONG_MAX,LONG_LONG_MIN};
    long long m=(l+r)/2;
    if(m>=idx){
        return getnum(num,idx,l,m,(cur*2)+1);
    }
    else{
        return getnum(num,idx,m+1,r,(cur*2)+2);
    }
}
int main(){
    long long num,idx,val;
    scanf("%lld %lld %lld",&r,&c,&Q);
    for(age=0;age<Q;++age){
        scanf("%lld",&k);
        if(k==1){
            scanf("%lld %lld %lld",&num,&idx,&val);
            upd(num-1,idx-1,val,0,c-1,0);
        }
        else if(k==2){
            scanf("%lld %lld",&num,&val);
            tag[num-1]={val,age};
        }
        else if(k==3){
            scanf("%lld %lld",&num,&idx);
            x=getnum(num-1,idx-1,0,c-1,0);
            y=tag[num-1];
            if(y.second>x.second){
                printf("%lld\n",y.first);
            }
            else printf("%lld\n",x.first);
        }
        else{
            mn=LONG_LONG_MAX;
            for(long long i=0;i<r;++i){
                x=seg[i][0];
                y=tag[i];
                if(y.second>x.second){
                    mn=min(mn,y.first);
                }
                else mn=min(mn,x.first);
            }
            printf("%lld\n",mn);
        }
    }
}