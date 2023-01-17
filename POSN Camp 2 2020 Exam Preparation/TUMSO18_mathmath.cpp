//				11/5/2563
#include<bits/stdc++.h>
#define MAXRANGE 2000000
using namespace std;
unsigned long long int arr[MAXRANGE],n;
int q;
unsigned long long int idx;
void testcase(){
	scanf("%llu",&n);
	if(n==0) printf("9\n");
	else if(n<=MAXRANGE){
		idx=n-1;
		printf("%llu\n",arr[idx]);
	}
	else{
		printf("%llu\n",arr[MAXRANGE-1]+(567*(n-MAXRANGE)));
	}
}
main(){
	scanf("%d",&q);
	arr[0]=576;
	for(int i=1;i<MAXRANGE;i++){
		arr[i]=arr[i-1]+567;
	}
	while(q--){
		//printf("#%.0Lf  ",n);
		testcase();
	}
}
