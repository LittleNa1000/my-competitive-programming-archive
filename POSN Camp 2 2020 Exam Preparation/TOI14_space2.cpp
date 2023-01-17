//				29/5/2563 LAST EDIT: 30/5/2563
#include<bits/stdc++.h>
using namespace std;
int x,y,z;//		1=triangle	2=laamtud   0=square		
queue< pair<int,int> > q;
int n,m,shape,avl,i,j,stk;
char str[2505][2005]; //			1=NEVER BEEN IN Q 	2=ONCE IN Q
bool allzero;
main(){
	scanf("%d %d",&m,&n);
	for(int c=0;c<n;c++){
		scanf("%s",&str[stk]);
		allzero=1;
		for(int d=0;d<m;d++){
			if(str[stk][d]=='1'){
				allzero=0;
				break;
			}
		}
		if(allzero||c+1==n){
			for(int a=0;a<stk;a++){
				for(int b=0;b<m;b++){
					if(str[a][b]=='1'){
						str[a][b]='2';
						avl=0;	shape=0;
						if(a>0&&str[a-1][b]=='1'){
							q.push({a-1,b});
							str[a-1][b]='2';
							avl++;
						}
						if(a<n-1&&str[a+1][b]=='1'){
							q.push({a+1,b});
							str[a+1][b]='2';
							avl++;
						}
						if(b>0&&str[a][b-1]=='1'){
							q.push({a,b-1});
							str[a][b-1]='2';
							avl++;
						}
						if(b<m-1&&str[a][b+1]=='1'){
							q.push({a,b+1});
							str[a][b+1]='2';
							avl++;
						}
						if(avl==1) shape++;
						while(!q.empty()){
							i=q.front().first;	j=q.front().second;
							q.pop();
							/*if()*/{
								//printf("(%d,%d)\n",i,j);
								avl=0;
								if(i>0&&str[i-1][j]>='1'){
									if(str[i-1][j]=='1'){
										q.push({i-1,j});
										str[i-1][j]='2';
									}
									avl++;
								}
								if(i<n-1&&str[i+1][j]>='1'){
									if(str[i+1][j]=='1'){
										q.push({i+1,j});
										str[i+1][j]='2';
									}
									avl++;
								}
								if(j>0&&str[i][j-1]>='1'){
									if(str[i][j-1]=='1'){
										q.push({i,j-1});
										str[i][j-1]='2';
									}
									avl++;
								}
								if(j<m-1&&str[i][j+1]>='1'){
									if(str[i][j+1]=='1'){
										q.push({i,j+1});
										str[i][j+1]='2';
									}
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
			stk=0;
		}
		else stk++;
	}	
	printf("%d %d %d",x,z,y);
}
