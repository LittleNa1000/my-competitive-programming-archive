//				28/4/2563
#include<bits/stdc++.h>
using namespace std;
struct pos{
	unsigned char i,j;
	short int dist;
	short int bi,bj;
	bool visited[155][155];
};
queue<struct pos> q;
struct pos p;
short int ans=SHRT_MAX,ans_c;
bool arr[155][155];
unsigned char n,m,start_i,start_j,exit_i,exit_j;
vector< pair<short int,short int> > bomb;
void f(){ 
	while(!q.empty()){
		p=q.front();
		q.pop();
		/*printf("(%d,%d) dist =%d bomb(%d,%d) is_wall=%d visited: \n",p.i,p.j,p.dist,p.bi,p.bj,!arr[p.i][p.j]);
		for(short int i=0;i<n;i++){
			for(short int j=0;j<m;j++) {
				if(i==start_i-1&&j==start_j-1) printf("@");
				else if(i==exit_i&&j==exit_j) printf("k");
				else printf("%d",p.visited[i][j]);	
			}
			printf("\n");
		}*/
		if(p.i==exit_i&&p.j==exit_j){
			if(find(bomb.begin(),bomb.end(),make_pair(p.bi,p.bj))==bomb.end()){
				ans_c++;
				bomb.push_back(make_pair(p.bi,p.bj));
			}
			if(ans>p.dist) ans=p.dist;
			//printf("\t\t\t\t\t\t#%hd %hd\n",ans_c,p.dist);
		}
		else{
			p.visited[p.i][p.j]=1;
			p.dist++;
			if(p.j<m-1&&!p.visited[p.i][p.j+1]){ 
				if(!arr[p.i][p.j+1]&&p.bi==-1){
					p.j++;
					p.bi=p.i; p.bj=p.j;
					q.push(p);
					p.bi=-1; p.bj=-1;
					p.j--;
				}
				else if(arr[p.i][p.j+1]){
					p.j++;
					q.push(p);
					p.j--;	
				} 
			}
			if(p.i<n-1&&!p.visited[p.i+1][p.j]){
				if(!arr[p.i+1][p.j]&&p.bi==-1){
					p.i++;
					p.bi=p.i; p.bj=p.j;
					q.push(p);
					p.bi=-1; p.bj=-1;
					p.i--;
				}
				else if(arr[p.i+1][p.j]){
					p.i++;
					q.push(p);
					p.i--;	
				} 
			}
			if(p.j>0&&!p.visited[p.i][p.j-1]){
				if(!arr[p.i][p.j-1]&&p.bi==-1){
					p.j--;
					p.bi=p.i; p.bj=p.j;
					q.push(p);
					p.bi=-1; p.bj=-1;
					p.j++;
				}
				else if(arr[p.i][p.j-1]){
					p.j--;
					q.push(p);
					p.j++;
				} 
			}
			if(p.i>0&&!p.visited[p.i-1][p.j]){
				if(!arr[p.i-1][p.j]&&p.bi==-1){
					p.i--;
					p.bi=p.i; p.bj=p.j;
					q.push(p);
					p.bi=-1; p.bj=-1;
					p.j++;
				}
				else if(arr[p.i-1][p.j]){
					p.i--;
					q.push(p);
					p.i++;	
				} 
			}
		}
	}
}

main(){
	scanf("%d %d",&n,&m);
	scanf("%d %d",&start_i,&start_j);
	scanf("%d %d",&exit_i,&exit_j);
	exit_i--;
	exit_j--;
	for(short int i=0;i<n;i++){
		for(short int j=0;j<m;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	q.push({start_i-1,start_j-1,1,-1,-1,{}});
	f();
	printf("%hd\n%hd",ans_c,ans);
}
