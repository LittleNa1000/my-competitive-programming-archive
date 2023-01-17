//				12/6/2563 //FOR LOOP SOMETIMES WHEN NOT VACANT CHANGE MINP TO INT_MAX
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;
queue<pair<int,p> > q;
int t,n,temp,temp1,temp2,timer,minP=INT_MAX,minP_idx;
double ans;
bool vacant=1;
p process;
vector<pair<p,int> > wq;//{{priority,age},process time}
main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d %d %d",&temp,&temp1,&temp2);
			q.push({temp,{temp1,temp2}});	//{priority,time needed for processing}
		}
		timer=q.front().first;
		for(;;timer++){
			if(!q.empty()&&timer==q.front().first){
				wq.push_back({{q.front().second.first,timer},q.front().second.second});
				if(minP>q.front().second.first){
					minP=q.front().second.first;
					minP_idx=wq.size()-1;
				}
				q.pop();
			}
			if(process.second<=0){
				vacant=1;
			}
			else if(minP<process.first){
				wq.push_back({{process.first,timer},process.second});
				vacant=1;
			}
			if(vacant&&!wq.empty()){
				vacant=0;
				process.first=minP;
				process.second=wq[minP_idx].second;
				wq.erase(wq.begin()+minP_idx);
				minP=INT_MAX;
				for(int i=0;i<wq.size();i++){
					if(minP>wq[i].first.first-(timer-wq[i].first.second)){
							minP=wq[i].first.first-(timer-wq[i].first.second);
							minP_idx=i;
					}
				}
			}
			ans+=wq.size();
			process.first--;	process.second--;	minP--;
			if(vacant&&q.empty()) break;
		}
		printf("%.7lf\n",ans/n);
		vacant=1;	minP=INT_MAX;	ans=0;
	}
}
