//			26/3/2563
#include<bits/stdc++.h>
using namespace std;
int arr[10005],n,q,target;
bool subset_sum(int i,int j){
	if(j==0) return 1;
	if(i==0&&arr[i]==j) return 1;
	if(i==0&&arr[i]!=j) return 0;
	if(j<arr[i]) return subset_sum(i-1,j);
	return subset_sum(i-1,j)||subset_sum(i-1,j-arr[i]);
}
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d",&target);
		if(subset_sum(n-1,target)) printf("YES\n");
		else printf("NO\n"); 
	}
}
