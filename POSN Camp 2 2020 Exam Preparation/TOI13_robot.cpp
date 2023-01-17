//				14/5/2563		//OR RESET BOOLEAN OR USE CHAR INSTEAD OF BOOL
#include<bits/stdc++.h>
using namespace std;
char str[2005][2005];
char visited[2005][2005];
short int ans,ans_dist,n,m,item=1,qidx;
struct info{
	short int pi,pj;
	unsigned short int dist;
};
queue<struct info> q[101];
struct info x;
void f(){
	while(!q[qidx].empty()){
		x=q[qidx].front();
		q[qidx].pop();
		visited[x.pi][x.pj]=item;
		if(str[x.pi][x.pj]=='X'){
			ans++;
			ans_dist+=(x.dist*2);
			break;
		}
		if(x.pi>0&&str[x.pi-1][x.pj]!='W'&&visited[x.pi-1][x.pj]!=item){//	Up
			q[qidx].push({x.pi-1,x.pj,x.dist+1});
		}
		if(x.pi<n-1&&str[x.pi+1][x.pj]!='W'&&visited[x.pi+1][x.pj]!=item){//	Down
			q[qidx].push({x.pi+1,x.pj,x.dist+1});
		}
		if(x.pj>0&&str[x.pi][x.pj-1]!='W'&&visited[x.pi][x.pj-1]!=item){//	Left
			q[qidx].push({x.pi,x.pj-1,x.dist+1});
		}
		if(x.pj<m-1&&str[x.pi][x.pj+1]!='W'&&visited[x.pi][x.pj+1]!=item){//	Right
			q[qidx].push({x.pi,x.pj+1,x.dist+1});
		}
	}
}
main(){
	scanf("%hd %hd",&n,&m);
	for(short int i=0;i<n;i++){
		scanf("%s",&str[i]);
	}
	for(short int i=0;i<n;i++){
		for(short int j=0;j<m;j++){
			if(str[i][j]=='A'){
				q[qidx].push({i,j,0});
				f();
				item++;
				qidx++;
				//while(!q.empty()) q.pop();
			}
		}
	}
	printf("%hd %hd",ans,ans_dist);
}
/*
for(short int a=0;a<2000;a++){
	for(short int b=0;b<2000;b++) visited[a][b][0]=0;
}
*/
