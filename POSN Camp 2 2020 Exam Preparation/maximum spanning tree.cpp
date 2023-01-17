//				14/8/2563
#include<bits/stdc++.h>
using namespace std;
int par[200005];
struct t{
	int u,v,w;
};
bool operator<(const t &a,const t &b){
	return a.w<b.w;
}
int find_par(int x){
	if(par[x]==x) return x;
	return par[x]=find_par(par[x]);
}
priority_queue<t> pq;
int V,E,u,v,w,mst;
long long int ans;
main(){
	scanf("%d %d",&V,&E);
	for(int i=0;i<V;++i) par[i]=i;
	for(int i=0;i<E;++i){
		scanf("%d %d %d",&u,&v,&w);
		pq.push({u,v,w});
	}
	while(mst<V-1){
		u=pq.top().u;   v=pq.top().v;   w=pq.top().w;
		pq.pop();
		u=find_par(u);
		v=find_par(v);
		if(u!=v){
			par[max(u,v)]=par[min(u,v)];
			++mst;
			ans+=w-1;
		}
	}
	printf("%lld",ans);
}
