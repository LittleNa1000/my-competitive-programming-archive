//				8/5/2563
#include<bits/stdc++.h>
using namespace std;
int n,m,ans,t;
char temp[7005];
bool arr[7005][7005];
void f(){
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
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%s",&temp);
		//printf("%s",temp);
		for(int j=0;j<m;j++){
			if(temp[j]=='1'){
				arr[i][j]=1;
				ans++;
			}
		}
	}
	//printf("%d",ans);
	t=min(n,m);
	while(t--){
		printf("%d\n",ans);
		if(ans>0) f();
	}
}
