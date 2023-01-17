//				9/6/2563
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int> > p;
priority_queue<p,vector<p>,greater<p> > pq;
vector<p> v;
int n,m,t,type,tf,tf_to,w,value,target,action,x,mn;
main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<m+n;i++){
		//printf("TIME=%d\n",i);
		while(!pq.empty()&&i==pq.top().first){
			//printf("RUN at time=(%d) ",i);
			target=pq.top().second.first;
			action=pq.top().second.second;
			pq.pop();
			for(int j=0;j<v.size();j++){
				if(v[j].second.second==target){
					if(action==-1) v[j].first=INT_MAX;//erase
					else{
						if(v[j].first!=INT_MAX){
							//printf("change %d->%d ",v[j].first,action);
							v[j].first=action;
						}
					}
					break;
				}
			}
		}
		scanf("%d",&type);
		if(type==1){
			scanf("%d",&t);
			scanf("%d %d",&w,&value);
			if(t>=2){
				scanf("%d",&tf);
				tf_to=-1;
			}
			if(t==3){
				scanf("%d",&tf_to);
			}
			v.push_back({w,{value,i}});
			if(t>=2) pq.push({tf,{i,tf_to}});
		}
		else{
			mn=INT_MAX;
			for(int j=0;j<v.size();j++){	
				if(mn>v[j].first){
					mn=v[j].first;
					x=j;
				}
			}
			
			if(mn<INT_MAX){
				printf("%d\n",v[x].second.first);
				v[x].first=INT_MAX;//erase
			}
			else printf("0\n");
		}
	}
}
