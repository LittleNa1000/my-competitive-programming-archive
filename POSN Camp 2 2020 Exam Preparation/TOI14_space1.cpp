//				29/5/2563 CHANGED VISITED TO IN Q
#include<bits/stdc++.h>
using namespace std;
int x,y,z;//		1=triangle	2=laamtud   0=square		
queue< pair<int,int> > q;
int n,m,shape,avl,i,j;
char str[1005][1005];
bool visited[1005][1005];	
main(){
	scanf("%d %d",&m,&n);
	for(int a=0;a<n;a++){
		scanf("%s",&str[a]);
	}
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			if(str[a][b]=='1'&&!visited[a][b]){
				visited[a][b]=1;
				avl=0;	shape=0;
				if(a>0&&str[a-1][b]=='1'){
					q.push({a-1,b});
					avl++;
				}
				if(a<n-1&&str[a+1][b]=='1'){
					q.push({a+1,b});
					avl++;
				}
				if(b>0&&str[a][b-1]=='1'){
					q.push({a,b-1});
					avl++;
				}
				if(b<m-1&&str[a][b+1]=='1'){
					q.push({a,b+1});
					avl++;
				}
				if(avl==1) shape++;
				while(!q.empty()){
					i=q.front().first;	j=q.front().second;
					q.pop();
					if(!visited[i][j]){
						visited[i][j]=1;
						//printf("(%d,%d)\n",i,j);
						avl=0;
						if(i>0&&str[i-1][j]=='1'){
							if(!visited[i-1][j]) q.push({i-1,j});
							avl++;
						}
						if(i<n-1&&str[i+1][j]=='1'){
							if(!visited[i+1][j]) q.push({i+1,j});
							avl++;
						}
						if(j>0&&str[i][j-1]=='1'){
							if(!visited[i][j-1]) q.push({i,j-1});
							avl++;
						}
						if(j<m-1&&str[i][j+1]=='1'){
							if(!visited[i][j+1]) q.push({i,j+1});
							avl++;
						}
						if(avl==1) shape++;
					}
				}
				//printf("pic#%d is %d\n",x+y+z+1,shape);
				if(shape==0) x++;
				else if(shape==3) y++;
				else z++;
			}
		}
	}
	printf("%d %d %d",x,z,y);
}
