//				24/5/2563
#include<bits/stdc++.h>
using namespace std;
int n,m,temp,temp2,p;
int st_i=200,st_j=200,source,nxt;
char temp1,sym;
int ans[405][405],i[40005],j[40005];
queue< pair<int,char> > q[40005];
bool visited[40005];
queue<int> q2;
main(){
	scanf("%d %d",&n,&m);
	i[0]=200;	j[0]=200;
	p=(n*m)-1;
	for(int i=0;i<p;i++){
		scanf("%d %c %d",&temp,&temp1,&temp2);
		q[temp].push({temp2,temp1});
		if(temp1=='U') q[temp2].push({temp,'D'});
		else q[temp2].push({temp,'R'});
		//printf("%d %c %d\n",temp,temp1,temp2);
	}
	q2.push(0);
	while(!q2.empty()){
		source=q2.front();
		visited[source]=1;
		//printf("s=%d\n",source);
		q2.pop();
		while(!q[source].empty()){
			if(!visited[q[source].front().first]){
				sym=q[source].front().second;
				nxt=q[source].front().first;
				//printf("*%d %c %d*\n",source,sym,nxt);
				if(sym=='U'){
					i[nxt]=i[source]+1;
					j[nxt]=j[source];
				}
				else if(sym=='L'){
					i[nxt]=i[source];
					j[nxt]=j[source]+1;
				}
				else if(sym=='R'){
					i[nxt]=i[source];
					j[nxt]=j[source]-1;
					st_j=min(st_j,j[nxt]);
				}
				else{
					i[nxt]=i[source]-1;
					j[nxt]=j[source];
					st_i=min(st_i,i[nxt]);
				}
				//printf("pos of %d is(%d,%d)\n",nxt,i[nxt],j[nxt]);
				ans[i[nxt]][j[nxt]]=nxt;
				q2.push(nxt);
				//a++;
			}
			q[source].pop();
		}
	}
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			printf("%d ",ans[a+st_i][b+st_j]);
		}
		printf("\n");
	}
}
