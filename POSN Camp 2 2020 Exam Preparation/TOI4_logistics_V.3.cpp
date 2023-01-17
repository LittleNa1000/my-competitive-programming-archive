//				25/5/2563 TRY USING PQ INSTEAD OF MS // NO VISITED
#include<bits/stdc++.h>
using namespace std;
queue< pair<int,int> > q[30];
vector<int> v[50];
vector<char> path(1,'X');
bool broken,visited[30];
int source,nxt=27,dist,temp2,n;
char temp,temp1,c;
float median,ans;
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		//scanf("%c %c %d",&temp,&temp1,&temp2);
		cin>>temp>>temp1>>temp2;
		if(temp=='X') temp=27;
		else if(temp=='Y') temp=28;
		else temp-='a';
		if(temp1=='X') temp1=27;
		else if(temp1=='Y') temp1=28;
		else temp1-='a';
		q[temp].push({temp1,temp2});
		q[temp1].push({temp,temp2});
	}
	for(int i=0;!broken;i++){
		source=nxt;
		visited[source]=1;
		if(source<27) path.push_back(source+'a');
		if(source==28) break;
		broken=1;
		while(!q[source].empty()){
			c=q[source].front().first;
			dist=q[source].front().second;
			q[source].pop();
			if(!visited[c]){
				v[i].push_back(dist);
				broken=0;
				nxt=c;
			}
		}
	}
	if(broken) printf("broken");
	else{
		path.push_back('Y');
		for(int i=0;i<path.size()-1;i++){
			sort(v[i].begin(),v[i].end());
			if(v[i].size()%2) median=v[i][v[i].size()/2];
			else median=((float)v[i][v[i].size()/2]+(float)v[i][(v[i].size()/2)-1])/2;
			ans+=median;
			printf("%c %c %.1f\n",path[i],path[i+1],median);
		}
		printf("%.1f",ans);
	}
}
