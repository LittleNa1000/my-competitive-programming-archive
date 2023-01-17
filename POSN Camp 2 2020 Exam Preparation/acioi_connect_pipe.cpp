//			Last Edited: 1/4/2563
#include<bits/stdc++.h>
using namespace std;
int temp1,temp2,n,k,ans,d;
vector< pair<int,int> > v;
multiset<int> dist;
void find_distance(pair<int,int> home1,pair<int,int> home2){
	//printf("%d %d %d %d",home1.first,home1.second,home2.first,home2.second);
	d=abs(home1.first-home2.first)+abs(home1.second-home2.second);
	ans+=d;
	dist.insert(d);
}
main(){
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d %d",&temp1,&temp2);
		v.push_back(make_pair(temp1,temp2));
	}
	
	while(1<k--){
		ans-=*dist.rbegin();
		dist.erase(--dist.end());
	}
	printf("%d",ans);
}
