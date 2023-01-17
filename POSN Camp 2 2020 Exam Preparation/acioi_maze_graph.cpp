//				8/4/2563 Last Edited: 25/4/2563 V.2
#include<bits/stdc++.h>
using namespace std;
struct Node{
	short int a,b,d;
};
int n,m,i,j,dist,ans=-1;
char str[105][105];
bool visited[105][105];
stack<struct Node> st;
struct Node p;
void f(){
	while(!st.empty()){
		p=st.top();
		st.pop();
		i=p.a;
		j=p.b;
		dist=p.d;
		if(i==n-1&&j==m-1){
			if(dist<ans||ans==-1) ans=dist;	
		}
		else {
			visited[i][j]=1;	
		if(i>0&&str[i-1][j]!='#'&&!visited[i-1][j]){//	North
			//str[i-1][j]='#';
			st.push({i-1,j,dist+1});
		}
		if(j>0&&str[i][j-1]!='#'&&!visited[i][j-1]){//	West
			//str[i][j-1]='#';
			st.push({i,j-1,dist+1});
		}
		if(i<n-1&&str[i+1][j]!='#'&&!visited[i+1][j]){//	South
			//str[i+1][j]='#';
			st.push({i+1,j,dist+1});
		}
		if(j<m-1&&str[i][j+1]!='#'&&!visited[i][j+1]){//	East
			//str[i][j+1]='#';
			st.push({i,j+1,dist+1});
		}
		}
	}
}
main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		cin>>str[i];
	}
	st.push({0,0,0});
	f();
	printf("%d",ans);
}
