//				27/5/2563
#include<bits/stdc++.h>
using namespace std;
int n,k,m,temp,temp1,vacant,t,finish,idx;
typedef pair<int,pair<int,int> > p;
bool ans[500005];
priority_queue<p,vector<p>,greater<p> > pq;
priority_queue<int,vector<int>,greater<int> > process;
main(){
	scanf("%d %d %d",&n,&k,&m);
	vacant=k;
	for(int i=0;i<n;i++){
		scanf("%d %d",&temp,&temp1);
		pq.push({temp,{temp1,i+1}});
	}
	while(!pq.empty()){
		if(process.empty()) t=pq.top().first;
		else t=min(process.top(),pq.top().first);
		if(t==pq.top().first){
			finish=pq.top().second.first;
			idx=pq.top().second.second;
			pq.pop();
			if(vacant){
				vacant--;
				ans[idx]=1;
				process.push(finish);
			}
		}
		if(!process.empty()&&t==process.top()){
			process.pop();
			vacant++;
		}
	}
	for(int i=0;i<m;i++){
		scanf("%d",&temp);
		if(ans[temp]) printf("Y ");
		else printf("N ");
	}
}
