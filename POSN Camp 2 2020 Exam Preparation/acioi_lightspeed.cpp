//				10/6/2563
#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,ans,a,w1,w2,s,d;
int travel[1005],raw[1005],dist[1005][1005];
main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d",&travel[i]);
	}
	travel[m]=travel[0];
	for(int i=0;i<m;i++){
		scanf("%d",&raw[i]);
	}
	for(int i=1;i<m;i++){
		for(int j=0;j<i;j++){
			//From i to j
			x=0;	y=0;
			for(a=i;a!=j;a++){
				x+=raw[a];
				if(a==m-1) a=-1;
			}
			for(a=i;a!=j;a--){
				y+=raw[(a-1+m)%m];
				if(a==0) a=m;
			}
			dist[i][j]=min(x,y);
		}
	}
	/*for(int i=0;i<m;i++){
		for(int j=0;j<m;j++) printf("%d ",dist[i][j]);
		printf("\n");
	}*/
	while(n--){
		scanf("%d %d",&w1,&w2);
		ans=0;
		for(int i=0;i<m;i++){
			s=travel[i];	d=travel[i+1];
			x=max(s,d);		y=min(s,d);
			ans+=(min(dist[x][y],min(dist[max(s,w1)][min(s,w1)]+dist[max(w2,d)][min(w2,d)],dist[max(s,w2)][min(s,w2)]+dist[max(w1,d)][min(w1,d)])));
		}
		printf("%d\n",ans);
	}
	
}
