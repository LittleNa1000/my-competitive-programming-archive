//				21/4/2563
#include<bits/stdc++.h>
using namespace std;
int arr[105];
int n,i,j,x;
int t[105][105];
main(){
	scanf("%d",&n);
	for(int i=0;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	i=0;
	j=1;
	while(1){
		for(int k=i;k<j;k++){
			//printf("%d %d %d\n",i,j,k);
			if(k==i) 		 t[i][j]=t[i][k]+t[k+1][j]+(arr[i]*arr[k+1]*arr[j+1]);
			else t[i][j]=min(t[i][j],t[i][k]+t[k+1][j]+(arr[i]*arr[k+1]*arr[j+1]));
		}
		if(i==0&&j==n-1) break;
		if(j==n-1){
			i=0;
			j=1+(++x);
		}
		else{
			i++;
			j++;
		}
	}
	/*for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) printf("%d ",t[i][j]);
		printf("\n");
	}*/
	printf("%d",t[0][n-1]);
}
