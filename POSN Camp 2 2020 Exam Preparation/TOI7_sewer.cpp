//				7/5/2563
#include<bits/stdc++.h>
using namespace std;
int n,m,p_i,p_j,dist,ans=INT_MAX,ans_i,ans_j;
char arr[105][105];
bool visited[105][105];
void f(){
	//printf("(%d,%d) dist=%d\n",p_i,p_j,dist);
	if(visited[p_i][p_j]){
		if(ans>dist){
			ans=dist;
			ans_i=p_i;
			ans_j=p_j;
		}
		return ;
	}
	visited[p_i][p_j]=1;
	if(p_i<n-1&&(arr[p_i][p_j]=='D'||arr[p_i][p_j]=='B')){
		p_i++;	dist++;
		f();
		p_i--;	dist--;
	}
	if(p_j<m-1&&(arr[p_i][p_j]=='B'||arr[p_i][p_j]=='R')){
		p_j++;	dist++;
		f();
		p_j--;	dist--;
	}
}
main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	dist=1;
	f();
	printf("%d\n%d %d",ans,ans_i+1,ans_j+1);
}
