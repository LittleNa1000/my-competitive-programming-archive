//				30/8/2563
#include<bits/stdc++.h>
using namespace std;
struct Node{
	int a,b,c,d;
};
int par[100005];
long long int V,E,u,v,w,mst,idx,z,ans;
vector<int> re;
bool ticket=1;
bool com(const Node &x,const Node &y){
	return x.c>y.c;
}
int find_par(int x){
	if(par[x]==x) return x;
	return par[x]=find_par(par[x]);
}
vector<Node> edge;
bool check(){
	//return mst<V-1;
	for(int i=0;i<V;++i){ // maybe int previous;
		par[i]=find_par(par[i]);
		if(par[i]!=0) return 1;
	}
	return 0;
}
main(){
	scanf("%lld %lld",&V,&E);
	for(int i=0;i<V;++i) par[i]=i;
	for(int i=0;i<E;++i){
		scanf("%lld %lld %lld",&u,&v,&w);
		edge.push_back({u-1,v-1,w,i});
	}
	scanf("%lld",&z);
	sort(edge.begin(),edge.end(),com);
	for(int i=0;i<E&&!(mst==V-1&&!ticket);++i){ // maybe more if()
		u=edge[i].a;   v=edge[i].b;   w=edge[i].c;    idx=edge[i].d;
		u=find_par(u);
		v=find_par(v);
		if(u!=v){
			++mst;
			ans+=w;
			re.push_back(idx);
			par[max(u,v)]=par[min(u,v)];
		}
		else if(ticket){
			ticket=0;
			ans+=w;
			re.push_back(idx);
		}
	}
	
	if(check()){
		printf("-1");
	}
	else{
		printf("%lld\n",ans);
		if(z==2){
			for(int i=0;i<re.size();++i) printf("%d ",re[i]+1);
		}	
	}
	//printf("\n");
	//for(int i=0;i<V;++i) printf("%d ",par[i]);
}
