//				6/4/2563
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int> > p;
priority_queue<p> pq;
vector<int> minion[2505];
p high;
int master[2505],V,E,temp,temp1,temp2,mst_edge;// MST Part
int mst[2505][2505];				  		   // BFS and Calculation Part
queue<int> q;
int pre[2505],t,source,target,ppl,x,cal=INT_MAX;
long int ans;
bool visited[2505],b;
bool cycle(int start,int destination){ // and update master[i] if doesn't form a cycle
	if(master[start]==master[destination]) return 1;
	int a=max(master[start],master[destination]) , b=min(master[start],master[destination]);
	for(int i=0;i<minion[a].size();i++){//update all master
		master[minion[a][i]]=b;
		if(b!=0) minion[b].push_back(minion[a][i]);
		//printf("master[%d] = %d\n",i,master[i]);
	}
	return 0;
}
main(){
	scanf("%d %d",&V,&E);
	for(int i=0;i<E;i++){
		scanf("%d %d %d",&temp,&temp1,&temp2);
		pq.push(make_pair(temp2,make_pair(temp-1,temp1-1)));
		if(i<V){
			master[i]=i;
			minion[i].push_back(i);
		}
	}
	while(mst_edge+1<V){
		high=pq.top();
		pq.pop();
		if(!cycle(high.second.first,high.second.second)){
			mst_edge++;
			mst[high.second.first][high.second.second]=high.first;
			mst[high.second.second][high.second.first]=high.first;
		}
	}
	scanf("%d %d %d",&source,&target,&ppl);
	/*for(int i=0;i<V;i++){
		for(int j=0;j<V;j++) printf("%d\t",mst[i][j]);
		printf("\n");
	}*/
	source--;
	target--;
	q.push(source);
	visited[source]=1;
	pre[source]=-1;
	while(!q.empty()){
		t=q.front();
		//printf("t=%d\n",t);
		q.pop();
		for(int i=0;i<V;i++){
			if(!visited[mst[t][i]]&&mst[t][i]){
				visited[mst[t][i]]=1;
				q.push(i);
				pre[i]=t;
				if(i==target) {
					b=1;
					break;
				}
			}
		}
		if(b) break;
	}
	x=target;
	pre[x]=pre[target];
	while(pre[x]!=-1){
		//printf("x=%d pre[x]=%d mst[x][pre[x]]=%d\n",x,pre[x],mst[x][pre[x]]);
		if(cal>mst[x][pre[x]]) cal=mst[x][pre[x]];
		x=pre[x];
	}
	//printf("%d",cal);
	while(++ans){
		if(ceil((float)(ppl+ans)/ans)<=cal) break;
	}
	printf("%ld",ans);
}
