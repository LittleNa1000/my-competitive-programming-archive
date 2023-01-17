//				16/5/2563
#include<bits/stdc++.h>
using namespace std;
short int n,m,i,j;
char str[105][105];
bool visited[105][105];
queue< pair<short int,short int> > q;
main(){
	scanf("%hd %hd",&n,&m);
	for(short int a=0;a<n;a++){
		for(short int b=0;b<m;b++){
			//scanf("%c ",&str[a][b]);
			cin>>str[a][b];
		}
	}
	q.push({0,0});
	while(!q.empty()){
		i=q.front().first;
		j=q.front().second;
		q.pop();
		//printf("(%hd,%hd)\n",i,j);
		if(visited[i][j]){
			printf("%hd\n%hd %hd",i+j+1,i+1,j+1);
			break;
		}
		visited[i][j]=1;
		if(i<n-1&&(str[i][j]=='B'||str[i][j]=='D')){
			q.push({i+1,j});
		}
		if(j<m-1&&(str[i][j]=='B'||str[i][j]=='R')){
			q.push({i,j+1});
		}
	}
}
