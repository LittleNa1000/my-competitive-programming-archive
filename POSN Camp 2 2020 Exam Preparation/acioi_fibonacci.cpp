//			22/3/2563
#include<bits/stdc++.h>
using namespace std;
int f[5000005];
main(){
	int t,temp;
	f[1]=1;
	for(int i=2;i<=5000000;i++){
		f[i]=(f[i-1]+f[i-2])%1000000007;
		//printf("i=%d    %d\n",i,f[i]);
	}
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%d",&temp);
		printf("%d\n",f[temp]);
	}
}
