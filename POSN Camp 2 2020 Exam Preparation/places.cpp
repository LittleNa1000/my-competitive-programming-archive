//		places
#include<bits/stdc++.h>
using namespace std;
int vertice,totaledge,temp,ans;
vector< pair<int,int> > v[10000];//	vertice[1]={{2,30},{3,45}} //first=edge,second=distance
set<int> mst;
set<int>::iterator it;
priority_queue<int> pq;
bool connect(){
	if(mst.size()>=vertice) return 0;
	return 1;
}
main(){
	mst.insert(1);
	int a,b,c;
	scanf("%d %d",&vertice,&totaledge);
	//double the edges
	for(int i=0;i<totaledge;i++){
		scanf("%d %d %d",&a,&b,&c);
		v[a].push_back(make_pair(b,c));
		v[b].push_back(make_pair(a,c));
	}
	temp=1;
	bool bo;
	while(mst.size()<vertice){//	1=not connected 0=connected
		bo=0;
		//add edges to priority queue
		for(int i=0;i<v[temp].size();i++){
			it=mst.find(v[temp][i].first);
			if(it==mst.end()){
				//printf("added %d to pq ",v[temp][i].second);
				pq.push(v[temp][i].second);
			}
		}
		//find the maximum edge
		//add the destination vertice of that edge to set "mst" check if dest ver isn't in set mst
		int i,j;
		//printf(" ans%d+top%d",ans,pq.top());
		ans+=pq.top()-1;
		//printf("=%d",ans);
		for(i=1;i<=vertice;i++){
			for(j=0;j<v[i].size();j++){
				if(pq.top()==v[i][j].second){
					it=mst.find(v[i][j].first);
					if(it==mst.end()){
						temp=v[i][j].first;
						//printf(" insert %d to mst\n",temp);
						mst.insert(temp);
						bo=1;
						break;
					}
				}
			}
			if(bo) break;
		}
		pq.pop();
		//temp = the destination vertice
	}
	printf("%d",ans);
}
