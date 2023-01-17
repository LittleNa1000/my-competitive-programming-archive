//				19/5/2563
#include<bits/stdc++.h>
using namespace std;
char str[105][105];
bool visited[105][105],r;
int n,m,ans=INT_MAX,i,j,dist;
struct mz{
	int pi,pj,d;
};
queue<struct mz> q;
void f(){
	while(!q.empty()){
		i=q.front().pi; j=q.front().pj; dist=q.front().d;
		q.pop();
		//printf("(%d,%d) dist=%d \n",i,j,dist);
		if(i==n-1&&j==m-1){
			ans=min(ans,dist);
		}
		else if(!visited[i][j]){
		visited[i][j]=1;//VISITED FOR ALL IF
		if(i<n-1&&str[i+1][j]!='#'&&!visited[i+1][j]){
			q.push({i+1,j,dist+1});
		}
		if(j<m-1&&str[i][j+1]!='#'&&!visited[i][j+1]){
			q.push({i,j+1,dist+1});
		}
		if(i>0&&str[i-1][j]!='#'&&!visited[i-1][j]){
			q.push({i-1,j,dist+1});
		}
		if(j>0&&str[i][j-1]!='#'&&!visited[i][j-1]){
			q.push({i,j-1,dist+1});
		}}
	}	
}
main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%s",&str[i]);
	}
	q.push({0,0,0});
	f();
	if(ans!=INT_MAX) printf("%d",ans);
	else printf("-1");
}
