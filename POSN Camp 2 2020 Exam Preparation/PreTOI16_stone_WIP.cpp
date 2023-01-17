//				8/5/2563
#include<bits/stdc++.h>
using namespace std;
int n,m,ans,t;
char temp[7005];
bool arr[7005][7005];
int num[7005];
bool b;
void g(int i,int j,int x){
	b=0;
	for(int a=i;a<i+x;a++){
		for(int b=j;b<j+x;b++){
			printf("(%d,%d) ",a,b);
			if(a<n&&b<m){
				if(arr[a][b]==0) b=1;
			}
			else{
				b=1;
				break ;
			}
		}
	}
	if(b) return ;
	num[x]++;
	return g(i,j,x+1);
}
/*void f(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!arr[i][j]){
				if(j>0&&arr[i][j-1]){
					ans--;
					arr[i][j-1]=0;
				}
				if(i>0&&arr[i-1][j]){
					ans--;
					arr[i-1][j]=0;
				}
				if(j>0&&i>0&&arr[i-1][j-1]){
					ans--;
					arr[i-1][j-1]=0;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		if(arr[i][m-1]){
			ans--;
		}
		arr[i][m-1]=0;
	}
	for(int j=0;j<m-1;j++){
		if(arr[n-1][j]){
			ans--;
		}
		arr[n-1][j]=0;
	}
	
	n--;
	m--;
}*/
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%s",&temp);
		//printf("%s",temp);
		for(int j=0;j<m;j++){
			if(temp[j]=='1'){
				arr[i][j]=1;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]){
				num[0]++;
				g(i,j,1);
			}
		}
	}
	//printf("%d",ans);
	t=min(n,m);
	int y=0;
	while(t--){
		printf("%d\n",num[y]);
		y++;
	}
}
