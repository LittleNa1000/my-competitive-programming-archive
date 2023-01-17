//                  7/11/2563
#include<bits/stdc++.h>
using namespace std;
int n,q,k,l;
int pos[100005],dp[100005];
bool vst[100005];
priority_queue<int> pq;
void f(int st,int x,int c){
    vst[x]=1;
    if(st==x){
        printf("%d ",c);
        pq.push(c);
        return ;
    }
    return f(st,pos[x],c+1);
}
int main(){
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;++i){
        scanf("%d",&pos[i]);
    }
    for(int i=1;i<=n;++i){
        if(!vst[i]){
            vst[i]=1;
            f(i,pos[i],1);
        }
    }
    printf("GG");
    for(int i=0;!pq.empty();++i){
        dp[i]=pq.top();
        printf("%d: %d\n",i,dp[i]);
        if(dp[i]==1){
        	l=i;
        	break;
		}
        pq.pop();
        pq.push(dp[i]/2);
        if(dp[i]%2) pq.push((dp[i]/2)+1);
        else pq.push((dp[i]/2));
    }
    while(q--){
        scanf("%d",&k);// or more operation on pq if kis too much for dp
        if(k>=l) printf("%d\n",1);
        else printf("%d\n",dp[k]);
    }
}
