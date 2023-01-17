//				16/7/2563		Solving Method by lnwTum
//500000th Prime Number: 7368787
#include<bits/stdc++.h>
#define arrsize 7368800
using namespace std;
bool not_prime[arrsize];
int n,c=2,t;
main(){
	scanf("%d",&n);
	t=n;
	if(n==1) printf("2");
	else{
		for(int i=3;i<=arrsize;i+=2){
			n=t;
			if(!not_prime[i]){
				if(n==c){
					printf("%d",i);
					break;
				}
				c++;
				for(int j=i*2;j<=arrsize;j+=i) not_prime[j]=1;
			}
		}	
	}
}
