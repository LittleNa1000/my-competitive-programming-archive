//				23/5/2563
#include<bits/stdc++.h>
using namespace std;
struct bfs{
	int pi,pj,d,b;
};
int ans=INT_MAX,n,m,k,i,j,dist,bomb,si,sj;
char str[105][105];
bool fs;
int bomb_used[105][105];
queue<struct bfs> q;
main(){
	for(int a=0;a<105;a++){
		for(int b=0;b<105;b++) bomb_used[a][b]=INT_MAX;
	}
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<n;i++){
		scanf("%s",str[i]);
		if(!fs){
			for(int j=0;j<m;j++){
				if(str[i][j]=='S'){
					si=i;	sj=j;
					fs=1;
					break;
				}
			}
		}
	}
	q.push({si,sj,0,k});
	while(!q.empty()){
		i=q.front().pi;   j=q.front().pj;
		dist=q.front().d; bomb=q.front().b;
		q.pop();
		if(str[i][j]=='D'){
			//printf("YES(%d,%d) dist=%d bomb=%d \n",i,j,dist,bomb);
			ans=min(ans,dist);
		}
		else if(bomb_used[i][j]>k-bomb){
			//printf("(%d,%d) dist=%d bomb=%d \n",i,j,dist,bomb);
			bomb_used[i][j]=k-bomb;
			if(i>0){
				if(str[i-1][j]=='#'&&bomb>0) q.push({i-1,j,dist+1,bomb-1});
				else if(str[i-1][j]!='#') q.push({i-1,j,dist+1,bomb});
			}
			if(j>0){
				if(str[i][j-1]=='#'&&bomb>0) q.push({i,j-1,dist+1,bomb-1});
				else if(str[i][j-1]!='#') q.push({i,j-1,dist+1,bomb});
			}
			if(i<n-1){
				if(str[i+1][j]=='#'&&bomb>0) q.push({i+1,j,dist+1,bomb-1});
				else if(str[i+1][j]!='#') q.push({i+1,j,dist+1,bomb});
			}
			if(j<m-1){
				if(str[i][j+1]=='#'&&bomb>0) q.push({i,j+1,dist+1,bomb-1});
				else if(str[i][j+1]!='#') q.push({i,j+1,dist+1,bomb});
			}
		}
	}
	if(ans==INT_MAX) printf("-1");
	else printf("%d",ans);
}
