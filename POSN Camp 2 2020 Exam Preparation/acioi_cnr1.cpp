//			22/3/2563 	Old Code. A new one is "c(n,r) bottomup"
#include<bits/stdc++.h>
using namespace std;
long long int arr[1010][1010];
c(int n,int k){
	if(k==0||k==n){
		return 1;
	}
	if(arr[n][k]!=0) return arr[n][k];
	arr[n][k]=c(n-1,k-1)+c(n-1,k);
	return arr[n][k];
}
main(){
	int n,k,t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%d %d",&n,&k);
		printf("%lld",c(n,k)%1000000007);
	}
	
}
