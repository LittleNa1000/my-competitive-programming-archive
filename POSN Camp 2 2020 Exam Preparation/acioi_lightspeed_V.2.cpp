//				10/6/2563 LAST EDITED: 11/6/2563
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;
int n,m,x,y,ans,a,w1,w2,s,d,nxt,u;
int travel[1005],raw[1005],dist[1005][1005];
bool visited[1005];
main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++) if(i!=j) dist[i][j]=INT_MAX;
	}
	for(int i=0;i<m;i++){
		scanf("%d",&travel[i]);
	}
	travel[m]=travel[0];
	for(int i=0;i<m;i++){
		scanf("%d",&raw[i]);
	}
	for(int i=0;i<m;i++){
		//printf("R %d\n",i);
		priority_queue<p,vector<p>,greater<p> > pq;
		visited[i]=1;
		nxt=(i+1+m)%m;
		dist[i][nxt]=raw[i];
		pq.push({raw[i],nxt});
		nxt=(i-1+m)%m;
		dist[i][nxt]=raw[nxt];
		pq.push({raw[nxt],nxt});
		for(int j=0;j<m-1;j++){
			u=pq.top().second;		d=pq.top().first;
			pq.pop();
			//printf("NOW VISIT %d \n",u);
			visited[u]=1;
			nxt=(u+1+m)%m;
			if(!visited[nxt]&&d+raw[u]<dist[i][nxt]){
				//printf("UPDATE dist[%d][%d] %d->%d\n",i,nxt,dist[i][nxt],d+raw[u]);
				dist[i][nxt]=d+raw[u];
				pq.push({dist[i][nxt],nxt});
			}
			nxt=(u-1+m)%m;
			if(!visited[nxt]&&d+raw[nxt]<dist[i][nxt]){
				//printf("UPDATE dist[%d][%d] %d->%d\n",i,nxt,dist[i][nxt],d+raw[nxt]);
				dist[i][nxt]=d+raw[nxt];
				pq.push({dist[i][nxt],nxt});
			}
		}
		for(int j=0;j<m;j++) visited[j]=0;
	}
	/*for(int i=0;i<m;i++){
		for(int j=0;j<m;j++) printf("%d ",dist[i][j]);
		printf("\n");
	}*/
	while(n--){
		scanf("%d %d",&w1,&w2);
		ans=0;
		for(int i=0;i<m;i++){
			s=travel[i];	d=travel[i+1];
			x=max(s,d);		y=min(s,d);
			ans+=(min(dist[x][y],min(dist[max(s,w1)][min(s,w1)]+dist[max(w2,d)][min(w2,d)],dist[max(s,w2)][min(s,w2)]+dist[max(w1,d)][min(w1,d)])));
		}
		printf("%d\n",ans);
	}
	
}
