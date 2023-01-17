//				1/6/2563
#include<bits/stdc++.h>
using namespace std;
int bio[100005],his[100005]; // short int
int B,H,t,a,b,c,d,k,pbio,phis,biopg,hispg,book;
main(){
	scanf("%d %d %d",&B,&H,&t);
	for(int i=0;i<B;i++) scanf("%d",&bio[i]);
	for(int i=0;i<H;i++) scanf("%d",&his[i]);
	while(t--){
		scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
		pbio=a-1;	phis=b-1;
		for(book=0;book<k;book++){
			if((biopg+bio[pbio]<=hispg+his[phis]&&pbio<c)||phis>=d){
				biopg+=bio[pbio];
				pbio++;
			}
			else{
				hispg+=his[phis];
				phis++;
			}
		}
		printf("%d\n",max(biopg,hispg));
		biopg=0;	hispg=0;
	}
}
