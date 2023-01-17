#include "emergency.h"
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
vector<ii> edge[200005];
int ans,dist[200005],dep[200005],par[200005][20],mxl,sc,h_left=INT_MAX,qsum[200005];
int c_left=INT_MAX,c_right,h_right,sz;
bool isH[200005],isC[2000005];
float lgn;
void dfs(int u,int pre,int d){
	//if(visited[v]) return ;
	//visited[v]=1;
	if(pre!=-1) dep[u]=dep[pre]+1;
	if(pre!=-1) par[u][0]=pre;
	dist[u]=d;
	for(int i=1;i<=lgn;++i){
		par[u][i]=par[par[u][i-1]][i-1];
	}
	for(int i=0;i<edge[u].size();++i){
		int v=edge[u][i].first;
		int w=edge[u][i].second;
		if(v!=pre){
			dfs(v,u,d+w);
		}
	}
}
int lca(int u,int v){
	if(u==v) return u;
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=lgn;i>=0;--i){
		if(dep[par[u][i]]>=dep[v]){
			u=par[u][i];
		}
	}
	if(u==v) return u;
	for(int i=lgn;i>=0;--i){
		if(par[u][i]!=par[v][i]){
			u=par[u][i];
			v=par[v][i];
		}
	}
	return par[u][0];
}
void dfs_2(int u,int pre,int d,int cnt){
	qsum[cnt]=d;
	if(isH[u]){
		h_left=min(h_left,cnt);
		h_right=cnt;
	}
	if(isC[u]){
		c_left=min(c_left,cnt);
		c_right=cnt;
	}
	for(int i=0;i<edge[u].size();++i){
		int v=edge[u][i].first;
		int w=edge[u][i].second;
		if(v!=pre){
			dfs_2(v,u,d+w,cnt+1);
		}
	}
}
int dist_2(int l,int r){
	//printf("(%d,%d) d %d\n",l,r,qsum[r]-qsum[l]);
	return qsum[r]-qsum[l];
}
int furthest(int N, int H, int K,
	     int roads[][2],
	     int lengths[],
	     int hospitals[],
	     int centers[])
{
	int u,v,x,chi,chj;
	lgn=log2(N);
	for(int i=0;i<N-1;++i){
		edge[roads[i][0]].push_back({roads[i][1],lengths[i]});
		edge[roads[i][1]].push_back({roads[i][0],lengths[i]});
	}
	for(int i=0;i<N;++i){
		sz=edge[i].size();
		mxl=max(mxl,sz);
		if(sz==1) sc=i;
	}
	if(mxl==2){
		//printf("sc %d\n",sc);
		for(int i=0;i<H;++i){
			isH[hospitals[i]]=1;
		}
		for(int i=0;i<K;++i){
			isC[centers[i]]=1;
		}
		dfs_2(sc,-1,0,0);
		// for(int i=0;i<N;++i){
		// 	printf("%d ",qsum[i]);
		// } printf("\n");
		//printf("HL %d HR %d CL %d CR %d\n",h_left,h_right,c_left,c_right);
		return max(dist_2(h_left,c_right),dist_2(c_left,h_right));
	}
	dfs(0,-1,0); //maybe other sc
	//for(int i=0;i<N;++i) printf("%d %d %d %d %d\n",i,dist[i],par[i][0],par[i][1],par[i][2]); printf("\n");
	for(int i=0;i<H;++i){
		for(int j=0;j<K;++j){
			u=hospitals[i];
			v=centers[j];
			x=lca(u,v);
			//printf("(%d,%d) = %d\n",u,v,x);
			if(ans<dist[u]+dist[v]-(2*dist[x])){
				ans=dist[u]+dist[v]-(2*dist[x]);
				chi=u;
				chj=v;
			}
		}
	}
	//printf("ans %d %d\n",chi,chj);
	return ans;
}