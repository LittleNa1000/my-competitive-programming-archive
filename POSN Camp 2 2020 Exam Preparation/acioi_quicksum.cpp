//				2/4/2563
#include<bits/stdc++.h>
using namespace std;
int arr[100005],sum,n,q,temp,start,stop;
main(){
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		sum+=temp;
		arr[i]=sum;
	}
	while(q--){
		scanf("%d %d",&start,&stop);
		printf("%d\n",arr[stop-1]-arr[start-2]);
	}
}
