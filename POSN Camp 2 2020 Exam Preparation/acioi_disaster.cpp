//		19/3/2020
#include<bits/stdc++.h>
using namespace std;
int totaledge;
int edgenum[27];//	edgenum[] = No of edges ex. edgenum[ 0 (A) ]=2;
char temp[3],source,last;
vector< /*pair< int,*/ pair<char,char> /*>*/ > v; //Edges (visited,(start,finish))
//change from visited system to idx for displaying
/*void test(){
	for(int i=0;i<26;i++){
		if(edgenum[i]!=0)printf("%c has %d connecting edges\n",i+'A',edgenum[i]);
	}
	printf("Total edges: %d, Size of vector: %d\n",totaledge,v.size());
	for(int i=0;i<v.size();i++){
		printf("Edges #%d: goes from %c to %c with idx %d\n",v[i].first,v[i].second.first,v[i].second.second,v[i].first);
	}
	printf("Picked up %c for the source node\n",source);
}*/
main(){
	scanf("%d",&totaledge);
	for(int i=0;i<totaledge;i++){
		scanf("%s",&temp);
		edgenum[temp[0]-'A']++;
		edgenum[temp[1]-'A']++;
		v.push_back(/*make_pair(v.size(),*/make_pair(temp[0],temp[1])/*)*/);
		v.push_back(/*make_pair(v.size(),*/make_pair(temp[1],temp[0])/*)*/);
	}
	for(int i=0;i<26;i++){
		if(edgenum[i]==1){
			source=i+'A';
			break;
		}
		else if(edgenum[i]!=0){
			if(last==0) last=i+'A';
			if(edgenum[i]%2==1){
				source=i+'A';
				break;
			}
		}
	}
	if(source==0) source=last;
	//test();
	printf("%c ",source);
	
	while(v.size()!=0){
		for(int i=0;v.size();i++){
			if(v[i]./*second.*/first==source){
				source=v[i]./*second.*/second;
				printf("%c ",source);
				
				
				//printf("Deleting edge#%d(from %c to %c)\n",v[i].first,v[i].second.first,v[i].second.second);
				v.erase(v.begin()+i);
				if(i%2==0) {
					//printf("Deleting edge#%d(from %c to %c)\n",v[i+1].first,v[i+1].second.first,v[i+1].second.second);
					v.erase(v.begin()+i);
				} 
				else{
					//printf("Deleting edge#%d(from %c to %c)\n",v[i-1].first,v[i-1].second.first,v[i-1].second.second);
					v.erase(v.begin()+i-1);
				} 
				
				break;
			}
		}
	}
}
