//				23/5/2563 WIP
#include<bits/stdc++.h>
using namespace std;
bool wall[155][155],al_ans[155][155],visited[155][155];
int n,m,si,sj,ei,ej,ans_dist=INT_MAX,ans,i,j,dist,bi,bj;
struct bfs{
	int pi,pj,d,b_i,b_j;
};
queue<struct bfs> q;
main(){
	scanf("%d %d",&n,&m);
	scanf("%d %d %d %d",&si,&sj,&ei,&ej);
	si--;   sj--;   ei--;   ej--;
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			scanf("%d",&wall[a][b]);
		}
	}
	q.push({si,sj,1,-1,-1});
	while(!q.empty()){
		i=q.front().pi; j=q.front().pj; dist=q.front().d;
		bi=q.front().b_i;  bj=q.front().b_j;
		q.pop();
		if(i==ei&&j==ej){
			ans_dist=min(ans_dist,dist);
			if(bi!=-1&&!al_ans[bi][bj]){
				ans++;
				al_ans[bi][bj]=1;
				printf("ADDED (%d,%d) to al_ans\n",bi,bj);
			}
		}
		else if(!visited[i][j]){
			printf("(%d,%d) dist=%d use_bomb=(%d,%d)\n",i,j,dist,bi,bj);
			visited[i][j]=1;
			if(i>0&&!visited[i-1][j]){
				if(!wall[i-1][j]&&bi==-1) q.push({i-1,j,dist+1,i-1,j});
				else if(wall[i-1][j]) q.push({i-1,j,dist+1,bi,bj});
			}
			if(j>0&&!visited[i][j-1]){
				if(!wall[i][j-1]&&bi==-1) q.push({i,j-1,dist+1,i,j-1});
				else if(wall[i][j-1]) q.push({i,j-1,dist+1,bi,bj});
			}
			if(i<n-1&&!visited[i+1][j]){
				if(!wall[i+1][j]&&bi==-1) q.push({i+1,j,dist+1,i+1,j});
				else if(wall[i+1][j]) q.push({i+1,j,dist+1,bi,bj});
			}
			if(j<m-1&&!visited[i][j+1]){
				if(!wall[i][j+1]&&bi==-1) q.push({i,j+1,dist+1,i,j+1});
				else if(wall[i][j+1]) q.push({i,j+1,dist+1,bi,bj});
			}
		}
	}
	printf("%d %d",ans,ans_dist);
}
