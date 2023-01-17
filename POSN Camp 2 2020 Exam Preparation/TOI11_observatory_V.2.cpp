//				5/7/2563 Combine 2 for loop into one
#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=INT_MIN,temp;
int triangleright[2005][2005],triangleleft[2005][2005],down[2005][2005],R[2005][2005];
int dir[2005][2005],dil[2005][2005];
main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			scanf("%d",&temp);
			if(j>0) R[i][j]=temp+R[i][j-1];
			else R[i][j]=temp;
			if(i>0) down[i][j]=temp+down[i-1][j];
			else down[i][j]=temp;
			if(i>0&&j>0) dir[i][j]=temp+dir[i-1][j-1];
			else dir[i][j]=temp;
			if(i>0&&j<m-1) dil[i][j]=temp+dil[i-1][j+1];
			else dil[i][j]=temp;
		}
	}
	//triangleright
	for(int i=0;i<k;++i){
		triangleright[k-1][0]+=dir[k-1][i];
	}
	ans=max(ans,triangleright[k-1][0]);
	for(int i=k-1;i<n;++i){
		for(int j=1;j<=m-k;++j){
			triangleright[i][j]=triangleright[i][j-1]-down[i][j-1]+dir[i][j-1+k];
			if(i>k-1) triangleright[i][j]+=down[i-k][j-1]-dir[i-k][j-1];
			ans=max(ans,triangleright[i][j]);
		}
		if(i+1<n){
			triangleright[i+1][0]=triangleright[i][0]+R[i+1][k-1]-dir[i][k-1];
			ans=max(ans,triangleright[i+1][0]);
		}
	}
	//triangleleft
	for(int i=0;i<k;++i){
		triangleleft[k-1][m-1]+=dil[k-1][m-1-i];
	}
	ans=max(ans,triangleleft[k-1][m-1]);
	for(int i=k-1;i<n;++i){
		for(int j=m-2;j>=k-1;--j){
			triangleleft[i][j]=triangleleft[i][j+1]-down[i][j+1]+dil[i][j+1-k];
			if(i>k-1) triangleleft[i][j]+=down[i-k][j+1]-dil[i-k][j+1];
			ans=max(ans,triangleleft[i][j]);
		}
		if(i+1<n){
			triangleleft[i+1][m-1]=triangleleft[i][m-1]+R[i+1][m-1]-R[i+1][m-1-k]-dil[i][m-k];
			ans=max(ans,triangleleft[i+1][m-1]);
		}
	}
	/*printf("\n\n");
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j) printf("%d ",dil[i][j]);
		printf("\n");
	}
	printf("\n\n");
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j) printf("%d\t",triangleright[i][j]);
		printf("\n");
	}
	printf("\n\n");
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j) printf("%d\t",triangleleft[i][j]);
		printf("\n");
	}*/
	printf("%d",ans);
}
