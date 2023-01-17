//				23/6/2563
#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=INT_MIN,sum,j2;
int arr[2005][2005],qsum[2005][2005];
main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&arr[i][j]);
			qsum[i][j]=arr[i][j];
			if(i>0) qsum[i][j]+=qsum[i-1][j];
			if(j>0) qsum[i][j]+=qsum[i][j-1];
			if(i>0&&j>0) qsum[i][j]-=qsum[i-1][j-1];
			if(i>=k-1&&j>=k-1){
				sum=0;    j2=j;
				for(int p=0;p<k;++p,--j2){
					sum+=qsum[i][j2];
					if(j2>0) sum-=qsum[i][j2-1];
					if(i-k+p>=0){
						sum-=qsum[i-k+p][j2];
						if(j2>0) sum+=qsum[i-k+p][j2-1];
					}
				}
				ans=max(ans,sum);
			}
		}
	}
	for(int i=k-1;i<n;++i){
		for(int j=0;j+k-1<m;++j){
			sum=0;   j2=j;
			for(int p=0;p<k;++p,++j2){
				sum+=qsum[i][j2];
				if(j2>0) sum-=qsum[i][j2-1];
				if(i-k+p>=0){
						sum-=qsum[i-k+p][j2];
						if(j2>0) sum+=qsum[i-k+p][j2-1];
				}
			}
			ans=max(ans,sum);
		}
	}
	printf("%d",ans);
	/*for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) printf("%d ",qsum[i][j]);
		printf("\n");
	}*/
}
