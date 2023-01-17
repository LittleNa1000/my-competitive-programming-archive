//				4/4/2563 
#include<bits/stdc++.h>
using namespace std;
int V,temp,temp1,a,b;
//int edge[100005][70];
multiset<pair<int,int> > ms;
multiset<pair<int,int> >::iterator it;
char c=5;
bool not_same;
void testcase(){ //Edge = Vertices - 1
	scanf("%d",&V);
	for(int i=0;i<V-1;i++){
		scanf("%d %d",&temp,&temp1);
		a=min(temp,temp1);
		b=max(temp,temp1);
		ms.insert(make_pair(a,b));
		//edge[a][++edge[a][0]]=b;
		//edge.push_back(make_pair(temp1,temp));
	}
	for(int i=0;i<V-1;i++){
		scanf("%d %d",&temp,&temp1);
		if(!not_same){
			a=min(temp,temp1);
			b=max(temp,temp1);
			/*for(int j=1;j<=edge[a][0];j++){
				//printf("a=%d j=%d edge[a][j]=%d\n",a,j,edge[a][j]);
				if(edge[a][j]==b) break;
				if(j==edge[a][0]){
					printf("N");
					not_same=1;
				}
			}*/
			//edge.erase(it);
			it=ms.find(make_pair(a,b));
			if(it==ms.end()){
				not_same=1;
			}
			else ms.erase(it);
		}
	}
	if(!not_same) printf("Y");
	else printf("N");
	ms.clear();
}
main(){
	while(c--){
		testcase();
		//for(int i=0;i<100005;i++) edge[i][0]=0;
		not_same=0;
	}
}
