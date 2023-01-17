//				30/3/2563
#include<bits/stdc++.h>
using namespace std;
typedef pair<pair<char,char>,int> cci;
vector<cci> edge;
vector<char> path;
vector<int> dist[1000]; 
double ans,result;
char temp,temp1,s,f;
int temp2,n,med_size,idx;
bool broken;
void findmedian(vector<int> median){
	med_size=median.size();
	//for(int i=0;i<med_size;i++) printf("---%d--- ",median[i]);
	sort(median.begin(),median.end());
	if(median.size()%2==0){
		//printf("Selected %d ans %d to find result",median[s/2],median[(s/2)-1]);
		result=((float)median[med_size/2]+(float)median[(med_size/2)-1])/2;
	}
	else{
		result=median[med_size/2];
	}
}
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>temp>>temp1>>temp2;
		edge.push_back(make_pair(make_pair(temp,temp1),temp2));
	}
	//printf("Insert input successfully\n");
	path.push_back('X');
	while(!broken){
		for(int i=0;i<edge.size();i++){
			idx=path.size()-1;
			//printf("path[%d] = %c\n",idx,path[idx]);
			if(edge[i].first.first==path[idx]){
				if(idx==0){
					path.push_back(edge[i].first.second);
					dist[idx].push_back(edge[i].second);
				}
				else if(edge[i].first.second!=path[idx-1]){
					path.push_back(edge[i].first.second);
					dist[idx].push_back(edge[i].second);
				}
				else dist[idx-1].push_back(edge[i].second);
					//printf("Push %d to dist[%d]\n",edge[i].second,idx-1);
					edge.erase(edge.begin()+i);
					break;	
			}
			else if(edge[i].first.second==path[idx]){
				if(idx==0){
					path.push_back(edge[i].first.first);
					dist[idx].push_back(edge[i].second);
				}
				else if(edge[i].first.second!=path[idx-1]){
					path.push_back(edge[i].first.first);
					dist[idx].push_back(edge[i].second);
				}
				else dist[idx-1].push_back(edge[i].second);
					//printf("Push %d to dist[%d]\n",edge[i].second,idx-1);
					edge.erase(edge.begin()+i);
					break;
			}
			if(i==edge.size()-1) broken=1;
		}
		if(path[path.size()-1]=='Y') break;
	}
	//printf("Out of while loop\n");
	if(broken){
		printf("broken");
		return 0;
	}
	//printf("Begin printing the output\n");
	for(int i=0;i<path.size()-1;i++){
		for(int j=0;j<edge.size();j++){
			s=edge[j].first.second;
			f=edge[j].first.first;
			//printf("i=%d j=%d (%c,%c)\n",i,j,f,s);
			if((f==path[i]&&s==path[i+1])||(s==path[i]&&f==path[i+1])){
				//printf("Found additional edge. (%c,%c) with weight=%d push to dist[%d]\n",f,s,edge[j].second,i);
				dist[i].push_back(edge[j].second);
				edge.erase(edge.begin()+j);
				j--;
			}
		}
		//printf("Begin finding the median of dist[%d] with size=%d\n",i,dist[i].size());
		findmedian(dist[i]);
		printf("%c %c %.1lf\n",path[i],path[i+1],result);
		ans+=result;
	}
	printf("%.1lf",ans);
}
