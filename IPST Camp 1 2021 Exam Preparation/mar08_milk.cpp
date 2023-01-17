
//      19/2/2564
#include<bits/stdc++.h>
using namespace std;
int V,Q,u,v,par[100005];
char ch;
int find_par(int x){
    if(par[x]==x) return x;
    return par[x]=find_par(par[x]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf("%d %d",&V,&Q);
    for(int i=1;i<=V;++i){
        par[i]=i;
    }
    while(Q--){
        // for(int i=1;i<=V;++i){
        //     printf("%d %d\n",i,par[i]);
        // }
        //printf("\n");
        cin>>ch>>u>>v;
        u=find_par(u);
        v=find_par(v);
        if(ch=='c'){
            //if(uu!=vv){
                par[max(u,v)]=par[min(u,v)];
            //}
        }
        else{
            if(u==v){
                printf("yes\n");
            }
            else printf("no\n");
        }
    }
}