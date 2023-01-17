//				27/6/2563 BRUTE FORCE // maybe bool learn()
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;
vector<int> condition[100005];//maybe 2d array
vector<int> v[100005];
bool learnt[100005],in_func[100005];
int n,maxlevel,t,temp,temp1,temp2,ans=-1,currentlv=1,cost;
bool learn(int tech){
	if(in_func[tech]){
		return 0;
	}
	in_func[tech]=1;
	if(!learnt[tech]){
		for(int i=0;i<condition[tech].size();++i){
			if(!learn(condition[tech][i])) return 0;
		}
		//printf("*%d*\n",tech);
		learnt[tech]=1;
		cost++;
	}
	in_func[tech]=0;
	return 1;
}
bool can_develop(int lv){
	for(int i=0;i<v[lv].size();++i){
		if(!learn(v[lv][i])||cost>t) return 0;
	}
	return 1;
}
main(){
	scanf("%d %d %d",&n,&maxlevel,&t);
	for(int i=0;i<n;++i){//can be 0
		scanf("%d %d",&temp,&temp1);
		for(int j=0;j<temp1;++j){
			scanf("%d",&temp2);
			condition[i].push_back(temp2-1);
		}
		v[temp].push_back(i);
	}
	for(;currentlv<=maxlevel&&cost<=t;++currentlv){
		if(can_develop(currentlv)){
			ans=currentlv;
		}
		else{
			break;
		}
	}
	printf("%d",ans);
}
