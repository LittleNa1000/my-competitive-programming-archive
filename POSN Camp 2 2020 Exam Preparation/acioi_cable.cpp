//				26/4/2563
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int> > p;
priority_queue<p,vector<p>,greater<p> > pq;
p lowest;
int V,temp,E,ans,start,finish,mn,mx;
vector<int> master[1005];
bool cycle(int a,int b){
	if(master[a][0]==master[b][0]) return 1;
	mn=min(master[a][0],master[b][0]);
	mx=max(master[a][0],master[b][0]);
	for(int i=0;i<master[mx].size();i++){
		master[mn].push_back(master[mx][i]);
		master[master[mx][i]][0]=mn;
	}
	return 0;
}
main(){
	scanf("%d",&V);
	for(int i=0;i<V-1;i++){
		master[i].push_back(i);
		for(int j=i+1;j<V;j++){
			scanf("%d",&temp);
			pq.push(make_pair(temp,make_pair(i,j)));
		}
	}
	master[V-1].push_back(V-1);
	while(E<V-1){
		lowest=pq.top();
		pq.pop();
		start=lowest.second.first;
		finish=lowest.second.second;
		//printf("Looking at %d-->%d dist=%d ",start,finish,lowest.first);
		if(!cycle(start,finish)){
			E++;
			ans+=lowest.first;
			//printf("Selected this Edge for MST");
		}
		//printf("\n");
	}
	printf("%d",ans);
}
