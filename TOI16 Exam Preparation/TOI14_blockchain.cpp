//				26/11/2563 1st ver: 28/5/2563
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,q,temp,temp1,temp2,mn,mx,ans,x;
map<vector<pii>,int > mp;
int main(){
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++){
        vector<pii> v;
		scanf("%d",&temp);
		for(int j=0;j<temp-1;j++){
			scanf("%d %d",&temp1,&temp2);
			mn=min(temp1,temp2);
			mx=max(temp1,temp2);
			//printf("push %f to pq %d\n",mn+((float)mx/temp),i);
			v.push_back({mn,mx});
		}
		sort(v.begin(),v.end());
        ++mp[v];
	}
	while(q--){
		ans=0;
		scanf("%d",&temp);
        vector<pii> u;
		for(int i=0;i<temp-1;i++){
			scanf("%d %d",&temp1,&temp2);
			mn=min(temp1,temp2);
			mx=max(temp1,temp2);
			//printf("push %f to pq2[%d]\n",mn+((float)mx/temp),x);
			u.push_back({mn,mx});
		}
		sort(u.begin(),u.end());
		printf("%d\n",mp[u]);
	}
}
