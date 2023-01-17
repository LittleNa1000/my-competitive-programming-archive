//				2/5/2563
#include<bits/stdc++.h>
using namespace std;
unsigned short int n,p,q,r,mx;
bool pattern[50005][75];
main(){
	scanf("%hu",&n);
	for(unsigned short int i=0;i<n;i++){
		scanf("%hu %hu %hu",&p,&q,&r);
		mx=max(mx,p);
		for(unsigned short int j=0;j<r;j++){
			if(j+q-1<70) pattern[p-1][j+q-1]=1;
		}
	}
	for(unsigned short int i=0;i<mx;i++){
		for(short int j=0;j<70;j++){
			if(pattern[i][j]) printf("x");
			else printf("o");
		}
		printf("\n");
	}
}
