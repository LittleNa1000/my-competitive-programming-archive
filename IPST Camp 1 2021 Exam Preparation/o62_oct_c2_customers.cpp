//      18/2/2564
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
vector<ii> sIn[120005];
int fen[120005],store[120005];
int m,n,q,tem,ans,T,sz,pre,idx,val;
float lgn;
vector<int> sl[120005]; //Store List
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf("%d %d %d",&m,&n,&q);
    lgn=log2(float(n));
    for(int i=1;i<=n;++i){
        scanf("%d",&sz);
        for(int j=0;j<sz;++j){
            scanf("%d",&tem);
            sl[tem].push_back(i);
        }
    }
    for(int i=1;i<=m;++i){
        if(sl[i].size()>0){
            //printf("%d\n",i);
            sort(sl[i].begin(),sl[i].end());
            pre=-1;
            for(int j=0;j<sl[i].size();++j){
                if(pre+1==sl[i][j]){
                    sIn[i][sIn[i].size()-1].second=sl[i][j];
                }
                else{
                    sIn[i].push_back({sl[i][0],sl[i][0]});
                }
                pre=sl[i][j];
            }         
        }
    }
    while(q--){
        scanf("%d",&T);
        if(T==1){
            scanf("%d %d",&idx,&val);
            upd(idx,val-store[idx]);
            store[idx]=val;
        }
        else{
            scanf("%d",&idx);
            ans=0;
            if((sIn[idx].size()*lgn)<sl[idx].size()){
                for(int i=0;i<sIn[idx].size();++i){
                    //printf("%d %d\n",sIn[idx][i].first,sIn[idx][i].second);
                    ans+=(sum(sIn[idx][i].second)-sum(sIn[idx][i].first-1));
                }
            }
            else{
                for(int i=0;i<sl[idx].size();++i){
                    //printf("%d\n",sl[idx][i]);
                    ans+=store[sl[idx][i]];
                }
            }
            printf("%d\n",ans);
        }
    }
}