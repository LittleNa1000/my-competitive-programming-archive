//				29/3/2563 WIP
#include<bits/stdc++.h>
using namespace std;
bool broken=1;
float ans,result;
int E,temp2;
char temp,temp1;
vector< pair<char,int> > edge[1000];
vector<int> median;
void findmedian(int s){
	sort(median.begin(),median.end());
	if(median.size()%2==0){
		//printf("Selected %d ans %d to find result",median[s/2],median[(s/2)-1]);
		result=((float)median[s/2]+(float)median[(s/2)-1])/2;
	}
	else{
		result=median[s/2];
	}
}
main(){
	scanf("%d",&E);
	for(int i=0;i<E;i++){
		cin>>temp>>temp1>>temp2;
		//check();
		if(temp=='Y') 		edge[temp1-'a'+1].push_back(make_pair(temp,temp2));
		else if(temp1=='Y') edge[temp-'a'+1].push_back(make_pair(temp1,temp2));
		else if(temp=='X') 	edge[0].push_back(make_pair(temp1,temp2));
		else if(temp1=='X') edge[0].push_back(make_pair(temp,temp2));
		else edge[min(temp,temp1)-'a'+1].push_back(make_pair(max(temp,temp1),temp2));
	}
	for(int i=0;i<30;i++){
		if(!edge[i].empty()){
			median.clear();
			for(int j=0;j<edge[i].size();j++){
				printf("edge[%d] has destination to %c with dist %d\n",i,edge[i][j].first,edge[i][j].second);
				median.push_back(edge[i][j].second);
			}
			findmedian(median.size());
			if(i==0) printf("X %c %.1f\n",edge[i][0].first,result);
			else printf("%c %c %.1f\n",i+'a'-1,edge[i][0].first,result);
			ans+=result;
		}
	}
	printf("%.1f",ans);
}
