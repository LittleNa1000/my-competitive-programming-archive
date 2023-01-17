//				28/4/2563
#include<bits/stdc++.h>
using namespace std;
int arr[6000005];
int n,w,first,ans=INT_MIN,ans_w=1,sum,D;
int initial(int i){
	first+=arr[i-1];
	return first;
}
void cmp(int i){
	if(sum>ans){
		ans=sum;
		ans_w=i;
	}
}
main(){
	scanf("%d %d",&n,&w);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		if(ans<arr[i]) ans=arr[i];
	}
	first=arr[0];
	if(ans<=0) printf("0\n0");
	else{
		for(int i=2;i<=w;i++){
			D=i;
			sum=initial(D);
			cmp(i);
			for(int j=0;j<n-i-1;j++){
				sum=sum+arr[j+i]-arr[j];
				cmp(i);
			}
		}
		printf("%d\n%d",ans,ans_w);
	}
}
