//				3/4/2563
#include<bits/stdc++.h>
using namespace std;
int m,n,t1,t2,multiply,cmp,mn;
double cost[4][4];
double ans,mincost;
int findpriority(int i,int j){
	multiply=0;
	if(i>0&&j>0&&cost[i-1][j-1]!=-1) 	multiply++;
    if(i>0&&cost[i-1][j]!=-1) 		multiply++;
    if(i>0&&j+1<m&&cost[i-1][j+1]!=-1) 	multiply++;
    if(j>0&&cost[i][j-1]!=-1) 		multiply++;
    if(j+1<m&&cost[i][j+1]!=-1) 		multiply++;
    if(i+1<n&&j>0&&cost[i+1][j-1]!=-1) 	multiply++;
    if(i+1<n&&cost[i+1][j]!=-1) 		multiply++;
    if(i+1<n&&j+1<m&&cost[i+1][j+1]!=-1) multiply++;
	return multiply;
}
void addnearby(int i,int j){
	if(i>0&&j>0&&cost[i-1][j-1]!=-1) 	cost[i-1][j-1]+=cost[i][j]/10;
    if(i>0&&cost[i-1][j]!=-1) 		cost[i-1][j]+=cost[i][j]/10;
    if(i>0&&j+1<m&&cost[i-1][j+1]!=-1) 	cost[i-1][j+1]+=cost[i][j]/10;
    if(j>0&&cost[i][j-1]!=-1) 		cost[i][j-1]+=cost[i][j]/10;
    if(j+1<m&&cost[i][j+1]!=-1) 		cost[i][j+1]+=cost[i][j]/10;
    if(i+1<n&&j>0&&cost[i+1][j-1]!=-1) 	cost[i+1][j-1]+=cost[i][j]/10;
    if(i+1<n&&cost[i+1][j]!=-1) 		cost[i+1][j]+=cost[i][j]/10;
    if(i+1<n&&j+1<m&&cost[i+1][j+1]!=-1) cost[i+1][j+1]+=cost[i][j]/10;
}
main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%lf",&cost[i][j]);
		}
	}
	for(int a=0;a<m*n;a++){
		mn=0;
		t1=0;
		t2=0;
		mincost=INT_MAX;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(cost[i][j]!=-1){
					cmp=findpriority(i,j);
					if(cost[i][j]<mincost||(cost[i][j]==mincost&&cmp>mn)){
							mn=cmp;
							mincost=cost[i][j];
							t1=i;
							t2=j;
					}
				}
			}
		}
		//printf("Bought (%d,%d) which costed %lf\n",t1,t2,cost[t1][t2]);
		ans+=cost[t1][t2];
		addnearby(t1,t2);
		cost[t1][t2]=-1;
		/*for(int a=0;a<n;a++){
			for(int b=0;b<m;b++) printf("%.2lf\t",cost[a][b]);
			printf("\n");
		}*/
	}
	printf("%.2lf",ans);
}
