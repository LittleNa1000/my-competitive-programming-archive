//				9/5/2563
#include<bits/stdc++.h>
using namespace std;
int arr[100005],l,r,k,n,q,sum,ans;
void f(int idx){
	if(idx>r) return ;
	//printf("%d\n",sum);
	if(sum+arr[idx]<k){
		sum+=arr[idx];
		f(idx+1);
		sum-=arr[idx];
	}
	else if(sum+arr[idx]==k){
		ans++;
		sum+=arr[idx];
		f(idx+1);
		sum-=arr[idx];
	}
	f(idx+1);
}
void testcase(){
	scanf("%d %d %d",&l,&r,&k);
	l--;	r--;
	f(l);
	printf("%d\n",ans%1000000007);
}
main(){
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	while(q--){
		testcase();
		ans=0;
		sum=0;
	}
}
