//				11-12/8/2563
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> pipii;
priority_queue<pipii,vector<pipii>,greater<pipii> > pq;
vector<pii> pack;
vector<int> d,price;
int par[3005];
int V,E,u,v,w,n,temp,temp1,mst,lb;
long long int ans;
bool built;
int find_par(int x){
	if(par[x]==x) return x;
	return par[x]=find_par(par[x]);
}
main(){
	scanf("%d %d",&V,&E);
	for(int i=0;i<V;++i) par[i]=i;
	for(int i=0;i<E;++i){
		scanf("%d %d %d %d",&u,&v,&w,&built);
		if(!built){
			pq.push({w,{u,v}});
		}
		else{
			u=find_par(u);
			v=find_par(v);
			if(u!=v){
				++mst;
				par[max(u,v)]=par[min(u,v)];
			}
		}
	}
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d %d",&temp,&temp1);
		pack.push_back({temp,temp1});
	}
	sort(pack.begin(),pack.end());
	for(int i=n-1;i>0;--i){
		//delete useless package here
		if(pack[i].second<=pack[i-1].second){
			pack.erase(pack.begin()+i-1);
		}
	}
	for(int i=0;i<pack.size();++i){
		//printf("%d %d\n",pack[i].first,pack[i].second);
		d.push_back(pack[i].first);
		price.push_back(pack[i].second);
	}
	while(mst<V-1){
		w=pq.top().first;   u=pq.top().second.first;   v=pq.top().second.second;
		pq.pop();
		u=find_par(u);
		v=find_par(v);
		if(u!=v){
			++mst;
			par[max(u,v)]=par[min(u,v)];
			lb=lower_bound(d.begin(),d.end(),w)-d.begin();
			ans+=price[lb];
		}
	}
	printf("%lld",ans);
}
