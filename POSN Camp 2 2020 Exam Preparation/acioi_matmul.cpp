//				23/4/2563
#include<bits/stdc++.h>
using namespace std;
int m,n,p,result;
int a[105][105],b[105][105];
int matmul(int x,int y){
	result=0;
	for(int i=0;i<n;i++){
		result+=(a[x][i]*b[i][y]);
	}
	return result;
}
main(){
	scanf("%d %d %d",&m,&n,&p);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<p;j++){
			scanf("%d",&b[i][j]);
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<p;j++){
			printf("%d ",matmul(i,j));
		}
		printf("\n");
	}
}
