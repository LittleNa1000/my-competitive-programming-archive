//			25/3/2563
#include<bits/stdc++.h>
using namespace std;

int t,V,E,master[1005],temp,temp1;
vector<int> minion[1005];
vector< pair<int,int> > v;

bool check_cycle(int start,int destination){
	if(master[start]==master[destination]) return 1;
	int a=max(master[start],master[destination]) , b=min(master[start],master[destination]);
	for(int i=0;i<minion[a].size();i++){//update all master
		master[minion[a][i]]=b;
		if(b!=0) minion[b].push_back(minion[a][i]);
	}
	/*for(int i=0;i<V;i++){
		printf("master[%d]=%d\n",i,master[i]);
	}*/
	return 0;
}
void testcase(){
	scanf("%d %d",&V,&E);
	for(int i=0;i<max(V,E)&&E!=0;i++){
		if(i<E){
			scanf("%d %d",&temp,&temp1);
			v.push_back(make_pair(temp,temp1));
		}
		if(i<V){
			//minion[i].clear();
			master[i]=i;
			minion[i].push_back(i);
		}
	}
	for(int i=0;i<v.size();i++){
		if(check_cycle(v[i].first,v[i].second)){
			printf("YES\n");
			return ;
		}
	}
	printf("NO\n");
}
main(){
	scanf("%d",&t);
	while(t--){
		testcase();
		v.clear();
		for(int c=0;c<1005;c++){
			master[c]=c;
			minion[c].clear();
		}
	}
}
