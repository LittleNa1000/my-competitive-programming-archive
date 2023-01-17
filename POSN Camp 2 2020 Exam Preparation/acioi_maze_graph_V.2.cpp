//				29/4/2563 WIP
#include<bits/stdc++.h>
using namespace std;
short int ans=-1,dist,n,m;
bool visited[105][105];
string str[105];
void f(unsigned char i,unsigned char j){
	//printf("(%d,%d)\n",i,j);
	if(i==n-1&&j==m-1){
		if(dist<ans||ans==-1){
			ans=dist;
		}
		return ;
	}
	visited[i][j]=1;
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			printf("%d ",visited[x][y]);
		}
		printf("\n");
	}
	printf("\n");
	if(j<m-1&&str[i][j+1]!='#'&&!visited[i][j+1]){
		dist++;
		f(i,j+1);
		dist--;
	}
	if(i<n-1&&str[i+1][j]!='#'&&!visited[i+1][j]){
		dist++;
		f(i+1,j);
		dist--;
	}
	if(j>0&&str[i][j-1]!='#'&&!visited[i][j-1]){
		dist++;
		f(i,j-1);
		dist--;
	}
	if(i>0&&str[i-1][j]!='#'&&!visited[i-1][j]){
		dist++;
		f(i-1,j);
		dist--;
	}
	visited[i][j]=0;
}
main(){
	scanf("%hd %hd",&n,&m);
	for(short int i=0;i<n;i++){
		cin>>str[i];
	}
	f(0,0);
	printf("%hd",ans);
}
