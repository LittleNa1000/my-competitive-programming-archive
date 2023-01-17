//				30/3/2563
#include<bits/stdc++.h>
using namespace std;
int n,start,h,finish,prev_h=-1;
int height[100005];
vector< pair<int,int> > v; // X pos, Height
void update_dot(int dot){
	for(int i=0;i<v.size();i+=2){
		if(v[i].first<=v[dot].first&&(dot!=i&&dot!=i+1)){
			//printf("First if() passes %d!=%d&&%d!=%d\n",dot,i,dot,i+1);
			if(v[i+1].first>=v[dot].first){
				if(height[i/2]>v[dot].second){
//printf("Update Dot #%d from (%d,%d) to (%d,%d) by Dot %d\n",dot,v[dot].first,v[dot].second,v[dot].first,v[i].second,i);
					v[dot].second=height[i/2];
				}
			}
		}
	}
}
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d %d",&start,&h,&finish);
		v.push_back(make_pair(start,h));
		v.push_back(make_pair(finish,0));
		height[i]=h;
	}
	for(int i=0;i<v.size();i++){
		update_dot(i);
		//printf("%d %d\n",v[i].first,v[i].second);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		if(prev_h!=v[i].second) printf("%d %d ",v[i].first,v[i].second);
		prev_h=v[i].second;
	}
}
