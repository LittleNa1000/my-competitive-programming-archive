//				26/7/2563
#include<bits/stdc++.h>
using namespace std;
int i,j,ai,aj,n,k,temp,temp1,ans;
bool visited[100005];
vector< pair<int,int> > l,r;
main(){
	scanf("%d %d",&n,&k);
	for(int x=0;x<n;++x){
		scanf("%d %d",&temp,&temp1);
		l.push_back({temp,x});
		r.push_back({temp1,x});
	}
	sort(l.begin(),l.end());
	sort(r.begin(),r.end());
	i=n-1;   j=n-1;
	while(ai+aj<n){
		//printf("(%d,%d)=(%d,%d) a(%d,%d)\n",i,j,l[i].first,r[j].first,ai,aj);
		if(j<0||(l[i].first>r[j].first&&ai-aj<k)||(l[i].first==r[j].first&&aj>ai)||aj-ai>=k){
			//printf("Choose Left");
			if(!visited[l[i].second]){
				//printf(" Add Left");
				++ai;
				ans+=l[i].first;
				visited[l[i].second]=1;
			}
			--i;
		}
		else{
			//printf("Choose Right");
			if(!visited[r[j].second]){
				//printf(" Add Right");
				++aj;
				ans+=r[j].first;
				visited[r[j].second]=1;
			}
			--j;
		}
		//printf("\n");
	}
	printf("%d",ans);
}
