//				20/4/2563
#include<bits/stdc++.h>
using namespace std;
int a,k,m,ans=1;
int arr[60];
float x;
main(){
	scanf("%d %d %d",&a,&k,&m);
	x=floor(log2(k));
	for(int i=0;i<=x;i++){
		if(i==0) arr[i]=a%m;
		else arr[i]=(arr[i-1]*arr[i-1])%m;
	}
	for(int i=0;i<=x;i++){
		if(k%2==1) ans*=arr[i];
		ans%=m;
		k/=2;
	}
	printf("%d",ans);
}
