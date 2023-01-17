//				7/5/2563
#include<bits/stdc++.h>
using namespace std;
int ans;
short int n,m,middle;
int step,i,j;
int area[105][105];
bool b;
struct bfs{
	short int pi,pj;
	int s;
};
queue<struct bfs> q;
void f(){
	while(!q.empty()){
		i=q.front().pi;   j=q.front().pj;   step=q.front().s;
		q.pop();
		printf("(%hd,%hd) step=%d\n",i,j,step);
		if(((i==middle-1&&j==0)||(i==middle&&j==0)||(i==middle+1&&j==0))&&step==1){
			b=1;
			break ;
		}
		if(step!=1){
			if(j>0&&area[i][j-1]&&(step-1)%area[i][j-1]==0){//		West
				q.push({i,j-1,step-1});
			}
			if(i%2==1){
				if(i>0&&j>0&&area[i-1][j-1]&&(step-1)%area[i-1][j-1]==0){//		NW
					q.push({i-1,j-1,step-1});
				}
				if(i<n-1&&j>0&&area[i+1][j-1]&&(step-1)%area[i+1][j-1]==0){//	SW
					q.push({i+1,j-1,step-1});
				}
			}
			if(i>0&&area[i-1][j]&&(step-1)%area[i-1][j]==0){//		North
				q.push({i-1,j,step-1});
			}
			if(i<n-1&&area[i+1][j]&&(step-1)%area[i+1][j]==0){//	South
				q.push({i+1,j,step-1});
			}
			if(j<m-1&&area[i][j+1]&&(step-1)%area[i][j+1]==0){//	East
				q.push({i,j+1,step-1});
			}
			if(i%2==0){
				if(i>0&&j<m-1&&area[i-1][j+1]&&(step-1)%area[i-1][j+1]==0){//	NE
					q.push({i-1,j+1,step-1});
				}
				if(i<n-1&&j<m-1&&area[i+1][j+1]&&(step-1)%area[i+1][j+1]==0){//	SE
					q.push({i+1,j+1,step-1});
				}
			}
		}
		
	}
	
}
main(){
	scanf("%hd %hd",&n,&m);
	for(short int a=0;a<n;a++){
		for(short int b=0;b<m;b++){
			scanf("%d",&area[a][b]);
		}
	}
	middle=(n-1)/2;
	for(ans=area[middle][m-1];;ans+=area[middle][m-1]){
		q.push({middle,m-1,ans});
		f();
		if(b){
			printf("%d",ans);
			break;
		}
	}
}
