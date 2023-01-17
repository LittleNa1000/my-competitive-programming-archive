//                  26/11/2563 or map<pii,piii>
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
struct HASH{
    size_t operator()(const pii &a)const{
        return a.first^a.second;
    }
};
unordered_map<pii,pii,HASH> mp(10000000);
int tx,ty,n,x,y,xx,yy;
pii p,tem[1505],tem2[1505];
int main(){
    scanf("%d %d %d",&tx,&ty,&n);
    for(int i=0;i<n;++i){
        scanf("%d %d",&x,&y);
        tem[i]={x,y};
    }
    for(int i=0;i<n;++i){
        scanf("%d %d",&x,&y);
        for(int j=0;j<n;++j){
            mp[{tem[j].first+x,tem[j].second+y}]=tem[j];
        }
    }
    for(int i=0;i<n;++i){
        scanf("%d %d",&x,&y);
        tem2[i]={x,y};
    }
    for(int i=0;i<n;++i){
        scanf("%d %d",&x,&y);
        for(int j=0;j<n;++j){
            xx=tem2[j].first+x; yy=tem2[j].second+y;
            p=mp[{tx-xx,ty-yy}];
            if(p.first!=0&&p.second!=0){
                printf("%d %d\n%d %d\n%d %d\n%d %d",p.first,p.second,tx-xx-p.first,ty-yy-p.second,tem2[j].first,tem2[j].second,x,y);
                return 0;
            }
        }
    }
}