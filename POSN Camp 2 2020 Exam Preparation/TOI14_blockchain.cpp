//				18/5/2563 LAST EDITED: 28/5/2563
#include<bits/stdc++.h>
using namespace std;
int n,q,temp,temp1,temp2,mn,mx,ans,x;
vector<double> v[1005],v2[1005];
main(){
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		for(int j=0;j<temp-1;j++){
			scanf("%d %d",&temp1,&temp2);
			mn=min(temp1,temp2);
			mx=max(temp1,temp2);
			//printf("push %f to pq %d\n",mn+((float)mx/temp),i);
			v[i].push_back(mn+((float)mx/temp));
		}
		sort(v[i].begin(),v[i].end());
	}
	for(x=0;x<q;x++){
		ans=0;
		scanf("%d",&temp);
		for(int i=0;i<temp-1;i++){
			scanf("%d %d",&temp1,&temp2);
			mn=min(temp1,temp2);
			mx=max(temp1,temp2);
			//printf("push %f to pq2[%d]\n",mn+((float)mx/temp),x);
			v2[x].push_back(mn+((float)mx/temp));
		}
		sort(v2[x].begin(),v2[x].end());
		for(int i=0;i<n;i++){
			if(v[i].size()==v2[x].size()&&v[i]==v2[x]){
				ans++;
			}
		}
		printf("%d\n",ans);
	}
}
