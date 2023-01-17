//      9/2/2564 or use queue
#include<bits/stdc++.h>
using namespace std;
int k,m,l,num,T,a,b,sz;
queue<int> q[100005];
int main(){
    scanf("%d %d",&k,&m);
    for(int i=0;i<k;++i){
        scanf("%d",&l);
        for(int j=0;j<l;++j){
            scanf("%d",&num);
            q[i].push(num);
        }
    }
    for(int i=0;i<m;++i){
        scanf("%d %d %d",&T,&a,&b);
        if(T==1){
            --a;
            sz=q[a].size();
            for(int j=0;j<sz;++j){
                if(q[a].front()!=b){
                    q[a].push(q[a].front());
                }
                q[a].pop();
            }
        }
        else{
            --a;
            --b;
            while(!q[b].empty()){
                q[a].push(q[b].front());
                q[b].pop();
            }
        }
    }
    for(int i=0;i<k;++i){
        while(!q[i].empty()){
            printf("%d\n",q[i].front());
            q[i].pop();
        }
    }
}