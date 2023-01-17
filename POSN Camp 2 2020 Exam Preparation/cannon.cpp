//		Cannon WIP
#include<bits/stdc++.h>
using namespace std;
struct Cannon{
	int pos;
	
}cannon[1000010];
string visited;
main(){
	//vector<int> v;
	int n,m,k,l,ans=0,temp;
	scanf("%d %d %d %d",&n,&m,&k,&l); //Cannon	supply	Formation	Rail_length
	for(int i=0;i<n;i++){
		scanf("%d",&cannon[i].pos);
		//visited[i]=0;
	}
	for(int i=0;i<k;i++){
		
		//v.clear();
		for(int j=0;j<m;j++){
			scanf("%d",&temp);
			for(int j2=0;j2<n;j2++){
				if(cannon[j2].pos>=temp-l&&cannon[j2].pos<=temp+l){
					//printf("checking %c ",visited[j2]);
					if(1){
						
						ans++;
						visited[j2]='2';
					}
				}
			}
		}
		printf("%d\n",ans);
		ans=0;
		visited.clear();
	}
	
}
