//				11/5/2563
#include<bits/stdc++.h>
using namespace std;
#define MAXARRAY 17500000
unsigned long long int arr[MAXARRAY],n,ans,p_1,p_2;
short int q;
void testcase(){
	scanf("%llu",&n);
	if(n<=MAXARRAY) printf("%llu\n",arr[n-1]);
	else{
		p_1=arr[MAXARRAY-1];	p_2=arr[MAXARRAY-2];
		for(int i=MAXARRAY+1;i<=n;i++){
			ans=((p_1*2)+p_2)%98765431;
			p_2=p_1;
			p_1=ans;
		}
		printf("%llu\n",ans);
	}
	
}
main(){
	scanf("%hd",&q);
	arr[0]=3;	arr[1]=7;
	for(int i=2;i<100;i++){
		arr[i]=((arr[i-1]*2)+arr[i-2])%98765431;
		if(i!=50) printf("%llu,",arr[i]);
	}
	while(q--){
		testcase();
	}
}
