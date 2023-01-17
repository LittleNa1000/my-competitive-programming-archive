//      24/2/2564
#include<bits/stdc++.h>
using namespace std;
set<int>::iterator it;
int T,n,Q,k,x,y,K,par[100005];
int find_par(int x){
    if(par[x]==x) return x;
    return par[x]=find_par(par[x]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf("%d",&T);
    while(T--){
        set<int> s[50005];
        scanf("%d %d",&n,&Q);
        for(int i=1;i<=n;++i){
            par[i]=i;
            //emplace
            s[i].insert(i);
        }
        while(Q--){
            scanf("%d",&K);
            if(K==1){
                scanf("%d %d",&x,&y);
                x=find_par(x);
                y=find_par(y);
                if(s[x].size()>=s[y].size()||(s[x].size()==s[y].size()&&x<y)){

                }
                else{
                    k=y;
                    y=x;
                    x=k;
                }
                for(it=s[y].begin();it!=s[y].end();++it){
                    s[x].insert(*it);
                    //printf("%d\n",*it);
                }
                par[y]=x;
                
            }
            else{
                scanf("%d",&x);
                y=x;
                x=find_par(x);
                printf("%d\n",distance(s[x].find(y),s[x].end()));
            }
        }
    }
}
