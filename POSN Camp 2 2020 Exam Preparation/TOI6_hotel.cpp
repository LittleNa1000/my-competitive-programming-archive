//				4/4/2563
#include<bits/stdc++.h>
using namespace std;
int n;
long int ans;
main(){
	scanf("%d",&n);
	ans+=3000*(n/15);
	n%=15;
	if(n>=8){
		printf("%ld",ans+3000);
	}
	else if(n==7){
		printf("%ld",ans+2500);
	}
	else if(n==6){
		printf("%ld",ans+2000);
	}
	else if(n==5){
		printf("%ld",ans+1500);
	}
	else if(n==4){
		printf("%ld",ans+1500);
	}
	else if(n==3){
		printf("%ld",ans+1300);
	}
	else if(n==2){
		printf("%ld",ans+800);
	}
	else{
		printf("%ld",ans+500);
	}
}
