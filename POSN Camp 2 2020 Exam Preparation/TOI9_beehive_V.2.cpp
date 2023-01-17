//				23/6/2563 //OR TOP GIVE NUMBERS TO BOTTOM
#include<bits/stdc++.h>
using namespace std;
int best[1005][1005],met[1005][1005],ans[10000005],maxans=INT_MIN;
int n,m,num;
main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			scanf("%d",&num);
			if(i==0){
				best[i][j]=num;
				met[i][j]=1;
			}
			else{
				if(i%2==1&&j<m-1){//mid vs. right
					if(best[i-1][j]>=best[i-1][j+1]){
						best[i][j]=best[i-1][j]+num;
						met[i][j]=met[i-1][j];
						if(best[i-1][j]==best[i-1][j+1]) met[i][j]+=met[i-1][j+1];
					}
					else if(best[i-1][j]<best[i-1][j+1]){
						best[i][j]=best[i-1][j+1]+num;
						met[i][j]=met[i-1][j+1];
					}
				}
				else if(i%2==0&&j>0){//mid vs. left
					if(best[i-1][j]>=best[i-1][j-1]){
						best[i][j]=best[i-1][j]+num;
						met[i][j]=met[i-1][j];
						if(best[i-1][j]==best[i-1][j-1]) met[i][j]+=met[i-1][j-1];
					}
					else if(best[i-1][j]<best[i-1][j-1]){
						best[i][j]=best[i-1][j-1]+num;
						met[i][j]=met[i-1][j-1];
					}
				}
				else{//just mid
					best[i][j]=best[i-1][j]+num;
					met[i][j]=met[i-1][j];
				}
			}
			if(i+1==n){
				if(maxans<=best[i][j]){
					maxans=best[i][j];
					//printf("(%d,%d)Now Max is %d, Met %d->%d\n",i,j,maxans,ans[maxans],ans[maxans]+met[i][j]);
					ans[maxans]+=met[i][j];
				}
			}
		}
	}
	printf("%d %d",maxans,ans[maxans]);
	/*for(int i=0;i<n;i++){
		printf("\n");
		for(int j=0;j<m;j++) printf("(%d,%d) ",best[i][j],met[i][j]);
	}*/
}
