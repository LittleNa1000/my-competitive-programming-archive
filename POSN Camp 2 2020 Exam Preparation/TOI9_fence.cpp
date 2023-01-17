//				12/7/2563 Solving Method by lnwTum
#include<bits/stdc++.h>
using namespace std;
int n,m,t,x,y,k,b;
int tree[505][505],tree2[505][505],qsum[505][505],qsum2[505][505];
main(){
	scanf("%d %d %d",&n,&m,&t);
	for(int i=0;i<t;++i){
		scanf("%d %d",&x,&y);
		tree[x+1][y+1]=1;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			qsum[i][j]=qsum[i-1][j]+qsum[i][j-1]-qsum[i-1][j-1]+tree[i][j];
			//printf("%d ",qsum[i][j]);
		}
		//printf("\n");
	}
	k=min(n,m);
	if(t==n*m) printf("0\n");
	for(;k>1;--k){
		for(int i=1;i<=n-k+1;++i){
			for(int j=1;j<=m-k+1;++j){
				b=qsum[i+k-1][j+k-1]-qsum[i+k-1][j-1]-qsum[i-1][j+k-1]+qsum[i-1][j-1]-qsum[i+k-2][j+k-2]+qsum[i+k-2][j]+qsum[i][j+k-2]-qsum[i][j];
				//printf("%d ",b);
				if(b==0) break;
			}
			//printf("\n");
			if(b==0) break;
		}
		if(b==0) break;
		//printf("\n\n");	
	}
	printf("%d\n",k);
	scanf("%d %d %d",&n,&m,&t);
	for(int i=0;i<t;++i){
		scanf("%d %d",&x,&y);
		tree2[x+1][y+1]=1;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			qsum2[i][j]=qsum2[i-1][j]+qsum2[i][j-1]-qsum2[i-1][j-1]+tree2[i][j];
			//printf("%d ",qsum[i][j]);
		}
		//printf("\n");
	}
	k=min(n,m);
	if(t==n*m) printf("0\n");
	for(;k>1;--k){
		for(int i=1;i<=n-k+1;++i){
			for(int j=1;j<=m-k+1;++j){
				b=qsum2[i+k-1][j+k-1]-qsum2[i+k-1][j-1]-qsum2[i-1][j+k-1]+qsum2[i-1][j-1]-qsum2[i+k-2][j+k-2]+qsum2[i+k-2][j]+qsum2[i][j+k-2]-qsum2[i][j];
				//printf("%d ",b);
				if(b==0) break;
			}
			//printf("\n");
			if(b==0) break;
		}
		if(b==0) break;
		//printf("\n\n");	
	}
	printf("%d\n",k);
}
