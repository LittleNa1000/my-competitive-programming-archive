//					6/5/2563 Boolean Table
#include<bits/stdc++.h>
using namespace std;
int n,ans,idx,mx;
int p[100005],h[100005];
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&p[i],&h[i]);
	}
	for(int i=0;i<n-1;i++){
		//printf("#%d ",i);
		queue<int> q;
		q.push(i);
		ans=i;
		while(!q.empty()){
			idx=q.front();
			q.pop();
			mx=INT_MIN;
			for(int j=idx+1;p[idx]+h[idx]>=p[j]&&j<n;j++){
				if(p[j]+h[j]>mx){
					ans=j;
					mx=p[j]+h[j];
				}
			}
			if(ans!=idx) q.push(ans);
			//printf("Push %d",ans);
		}
		printf("%d ",ans+1);
	}
	printf("%d",n);
}
