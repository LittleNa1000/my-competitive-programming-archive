//				14/5/2563
#include<bits/stdc++.h>
using namespace std;
int n,sum;
int ans[500005],p[500005],h[500005];
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&p[i],&h[i]);
		ans[i]=i;
	}
	for(int i=n-2;i>=0;i--){
		sum=p[i]+h[i];
		for(int j=i+1;j<n&&sum>=p[j];j++){
			ans[i]=max(ans[i],ans[j]);
		}
	}
	for(int i=0;i<n;i++) printf("%d ",ans[i]+1);
}
